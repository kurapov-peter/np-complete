# Graph coloring problem
## Problem statement
Graph coloring is an assignment of label (color) for each vertex in graph such that no two adjacent vertices are of the same color. The problem is to find assignment with minimal colors required (this number is called *chromatic number*)
**Applications**: scheduling, register allocation
### Greedy solution
Greedy coloring is iterating over all vertices in graph in some ordering and assigns first available color for current vertex (the first color that is not used in adjacent vertices; if all of them are used, we create new color). This alogithm has complexity *O(E)*, where *E* - number of edges (we check all adjacent vertices in each vertex, so the number of checks is *2 * E*). This approach doesn't guarantee that it will find the optimal coloring, but it can be prooved that for every graph there is a vertex ordering that gives an optimal solution with greedy algorithm. The problem of finding this ordering is itself NP-complete, but there is a simple heuristic that guarantees that number of colors will be no more than *d + 1*, where *d* - maximum vertex degree in this graph. This heuristic removes vertex with minimal degree from the graph and puts it in the end of requiried ordering, that process is repeated for leftover graph.
### DSatur solution
This algorithm has different ordering rule for vertices to be colored. It takes into account degree of saturation and first operates on vertex with the highest metric. This implementation operates in **O(V + E) log V** time, where **E** is the number of edges. Used *std::set* as red-black tree to order vertices. Also the containers of Graph have been modified for more appropriate access to Graph and Vertices. Overal it obtains better results then *Greedy algorithm* because of better data accesses, I think.
### Recursive largest first (RLF) solution
This algorithm assigns colors to a graph’s vertices by constructing each color class one at a time. It does this by identifying a maximal independent set of vertices in the graph, assigning these to the same color, and then removing these vertices from the graph. These actions are repeated on the remaining subgraph until no vertices remain.
### Brute-force solution
Graph with *N* vertices can be colored with no more than N colors, so we look over all posible chromatic colors starting from 1 and check if graph can be colored with *k* colors by iterating over all possible colorings (*k^N*, where *N* - number of vertices). So in the worst case (chromatic color = *N*, e.g. complete graph) the complexity is *O(1^N + 2^N + ... + N^N)*.

## Reports
CPU: i7-850H, 4.1 Ghz

| Test        | DSatur, ns     | Greedy, ns     | Bruceforce, ns     |
| ----------- | -------------- | -------------- | ------------------ |
| Complete/1  | 76.3           | 92.3           | 6.3                |
| Complete/2  | 174            | 200            | 29.2               |
| Complete/3  | 332            | 386            | 228                |
| Complete/4  | 550            | 629            | 3075               |
| Complete/5  | 884            | 989            | 53530              |
| Complete/6  | 1275           | 1436           | 975421             |
| Complete/7  | 1777           | 1962           | 20414142           |
| Complete/8  | 2363           | 2591           | 503830366          |
| Acyclic/1   | 76.1           | 92             | 6.34               |
| Acyclic/2   | 174            | 200            | 28.4               |
| Acyclic/3   | 274            | 305            | 60.3               |
| Acyclic/4   | 367            | 427            | 116                |
| Acyclic/5   | 500            | 536            | 275                |
| Acyclic/6   | 605            | 665            | 751                |
| Acyclic/7   | 701            | 772            | 2240               |
| Acyclic/8   | 824            | 951            | 6721               |
| Bipartite/1 | 174            | 200            | 28.9               |
| Bipartite/2 | 407            | 481            | 77.2               |
| Bipartite/3 | 786            | 878            | 185                |
| Bipartite/4 | 1264           | 1428           | 435                |
| Bipartite/5 | 1910           | 2111           | 1168               |
| Bipartite/6 | 2543           | 2972           | 2985               |
| Bipartite/7 | 3329           | 3777           | 8497               |
| Bipartite/8 | 4233           | 4807           | 24798              |

CPU: i7-1165G7, 2.80GHz
| Test        | RLF, ns        | DSatur, ns     | Greedy, ns     | Bruceforce, ns     |
| ----------- | -------------- | -------------- | -------------- | ------------------ |
| Complete/1  | 35.3           | 58.1           | 69.9           |      2.98          |
| Complete/2  | 72.1           |  146           |  175           |      10.9          |
| Complete/3  |  122           |  311           |  399           |       115          |
| Complete/4  |  170           |  499           |  592           |      1906          |
| Complete/5  |  231           |  786           |  865           |     34068          |
| Complete/6  |  294           | 1086           | 1179           |    691278          |
| Complete/7  |  369           | 1500           | 1568           |  14425749          |
| Complete/8  |  464           | 1998           | 2084           | 356425658          |
| Acyclic/1   | 36.6           | 60.1           | 67.8           |      3.01          |
| Acyclic/2   | 74.3           |  140           |  149           |      11.1          |
| Acyclic/3   |  131           |  234           |  243           |      29.5          |
| Acyclic/4   |  205           |  308           |  335           |      63.7          |
| Acyclic/5   |  279           |  410           |  421           |       149          |
| Acyclic/6   |  390           |  523           |  518           |       415          |
| Acyclic/7   |  522           |  627           |  603           |      1178          |
| Acyclic/8   |  656           |  711           |  761           |      3509          |
| Bipartite/1 | 74.9           |  140           |  152           |      11.2          |
| Bipartite/2 |  211           |  439           |  380           |      43.1          |
| Bipartite/3 |  426           |  837           |  714           |       129          |
| Bipartite/4 |  789           | 1189           | 1170           |       269          |
| Bipartite/5 | 1220           | 1641           | 1687           |       667          |
| Bipartite/6 | 1854           | 2367           | 2333           |      1725          |
| Bipartite/7 | 2601           | 2894           | 3005           |      4835          |
| Bipartite/8 | 3813           | 3688           | 3901           |     13389          |

