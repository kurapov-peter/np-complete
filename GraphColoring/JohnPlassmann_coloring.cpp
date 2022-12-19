
#include <algorithm>
#include <execution>
#include <mutex>

#include "graph.hpp"

namespace coloring {

namespace {

size_t weight(size_t i) { return (i * 2879 + 3449) % 104729; }

}  // namespace

// Take on realization of Johns-Plassmann parallel algorithm.
// More info: https://chenxuhao.github.io/docs/ipdpsw-2016.pdf
void JohnPlassmannColoring(Graph& G) {
  // Init worklist.
  std::set<Vertex::Idx> worklist;
  auto n = G.getNumVertices();

  for (Vertex::Idx i = 0u; i < n; ++i) {
    worklist.emplace(i);
  }

  std::set<Vertex::Idx> IS;
  std::set<Color> C;
  std::mutex m;

  while (!worklist.empty()) {
    // Form an independent set by looking at neighbours weight of each vertex,
    // and pick vertex if having maximum weight among its neighbours.
    // Do not look at already coloured vertices.
    // Also keep track of neighbours' color. Whole set will be assigned
    // the lowest available color next.
    // This could be done parallel with a bit of sync.

    std::for_each(std::execution::par, worklist.begin(), worklist.end(),
                  [&G, &worklist, &m, &IS, &C](auto& i) {
                    auto& v = G.getVertex(i);
                    auto vw = weight(i);
                    auto highestLocalWeight = std::all_of(
                        v.begin(), v.end(), [&worklist, &G, vw](auto& idx) {
                          return !worklist.count(idx) || weight(idx) < vw;
                        });
                    if (highestLocalWeight) {
                      // Fill neighbour color table
                      for (auto& neiIdx : v) {
                        auto& nei = G.getVertex(neiIdx);
                        if (nei.hasColor()) {
                          std::lock_guard<std::mutex> lg{m};
                          C.emplace(nei.getColor());
                        }
                      }

                      std::lock_guard<std::mutex> lg{m};
                      IS.emplace(i);
                    }
                  });

    // If we failed to find vertex with max weight - just pick first.
    if (IS.empty()) {
      IS.emplace(*worklist.begin());
      // Do not forget to fill neighbour color table.
      for (auto& neiIdx : G.getVertex(*IS.begin())) {
        auto& nei = G.getVertex(neiIdx);
        if (nei.hasColor()) {
          C.emplace(nei.getColor());
        }
      }
    }

    // Find the lowest common available color
    Color minColor = 1;
    while (C.count(minColor)) {
      minColor++;
    }
    if (G.getNumColors() < minColor) G.setMaxColor(minColor);

    // Assign same color to whole independent set. Done in parallel.
    std::for_each(
        std::execution::par, IS.begin(), IS.end(),
        [&G, minColor](auto& i) { G.getVertex(i).assignColor(minColor); });

    // Pop processed vertices from worklist
    for (auto& i : IS) {
      worklist.erase(i);
    }

    IS.clear();
    C.clear();
  }
}

}  // namespace coloring