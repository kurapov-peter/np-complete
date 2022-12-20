#include <algorithm>
#include <set>
#include <vector>

#include "graph.hpp"

namespace {

using namespace coloring;

struct VertexInfo {
  size_t N_Neighbours;
  Vertex::Idx VIdx;

  VertexInfo(size_t NN, Vertex::Idx Idx) : N_Neighbours(NN), VIdx(Idx) {}

  bool operator<(const VertexInfo &Other) const {
    return N_Neighbours != Other.N_Neighbours
               ? N_Neighbours < Other.N_Neighbours
               : VIdx < Other.VIdx;
  }
};

struct ExtendedVertexInfo {
  VertexInfo VI;
  size_t NAdjacentNeighbours;

  ExtendedVertexInfo(VertexInfo OtherVI, size_t NAN)
      : VI(OtherVI), NAdjacentNeighbours(NAN) {}

  bool operator<(const ExtendedVertexInfo &Other) const {
    return NAdjacentNeighbours != Other.NAdjacentNeighbours
               ? NAdjacentNeighbours < Other.NAdjacentNeighbours
               : VI < Other.VI;
  }
};

class RLFAnalysis final {
  Graph &G_;
  size_t N;
  std::set<VertexInfo> Input;
  std::set<Vertex::Idx> Colored;
  Color Clr = 0;

 public:
  RLFAnalysis(Graph &G) : G_(G), N(G.getNumVertices()) {
    for (size_t i = 0; i < N; ++i) {
      auto ToInsert = VertexInfo(G_.getVertex(i).getDegree(), i);
      Input.insert(ToInsert);
    }
  }

  void colorVertex(Vertex::Idx Idx) {
    G_.getVertex(Idx).assignColor(Clr);
    Colored.insert(Idx);
  }

  void selectVertex(decltype(Input)::iterator VII) {
    colorVertex(VII->VIdx);
    Input.erase(VII);
  }

  auto selectWithLargestNumOfNeighbours() {
    auto LargestNumOfNeighbours = std::prev(Input.end());
    selectVertex(LargestNumOfNeighbours);

    return LargestNumOfNeighbours->VIdx;
  }

  auto getAdjacentToColored(const std::set<VertexInfo> &ToCheck) {
    std::set<VertexInfo> Adjacent;
    std::for_each(ToCheck.begin(), ToCheck.end(),
                  [&Adjacent, this](const auto &VI) {
                    auto &V = G_.getVertex(VI.VIdx);
                    auto pos = std::find_if(
                        Colored.begin(), Colored.end(),
                        [&V](const auto C) { return V.isAdjacentVertex(C); });

                    if (pos != Colored.end()) Adjacent.insert(VI);
                  });
    return Adjacent;
  }

  auto getNNeighboursAdjacentToColored(Vertex::Idx VIdx) {
    auto NeighbourIters = G_.getVertex(VIdx).getAdjVIterators();
    size_t NNeighbours = 0;
    for (const auto &N : NeighbourIters) {
      auto pos =
          std::find_if(Colored.begin(), Colored.end(),
                       [&N](const auto &C) { return N->isAdjacentVertex(C); });
      if (pos != Colored.end()) ++NNeighbours;
    }

    return NNeighbours;
  }

  auto getNotAdjacentToColored(const std::set<VertexInfo> &ToCheck) {
    std::set<ExtendedVertexInfo> NotAdjacent;
    std::for_each(
        ToCheck.begin(), ToCheck.end(), [&NotAdjacent, this](const auto &VI) {
          auto &V = G_.getVertex(VI.VIdx);
          auto pos = std::find_if(
              Colored.begin(), Colored.end(),
              [&V](const auto C) { return V.isAdjacentVertex(C); });

          if (pos == Colored.end()) {
            auto NAdjacentNeighbours = getNNeighboursAdjacentToColored(VI.VIdx);
            if (NAdjacentNeighbours)
              NotAdjacent.emplace(VI, NAdjacentNeighbours);
          }
        });
    return NotAdjacent;
  }

  void colorIter() {
    Clr = G_.getNewColor();
    selectWithLargestNumOfNeighbours();
    auto NotAdjacentToColored = getNotAdjacentToColored(Input);
    while (!NotAdjacentToColored.empty()) {
      auto NextToSelect = Input.find(NotAdjacentToColored.rbegin()->VI);
      selectVertex(NextToSelect);
      NotAdjacentToColored = getNotAdjacentToColored(Input);
    }
  }

  void color() {
    while (!Input.empty()) {
      colorIter();
    }
  }
};
}  // namespace

namespace coloring {

void RLFColoring(Graph &G) {
  RLFAnalysis RLF(G);
  RLF.color();
}

}  // namespace coloring
