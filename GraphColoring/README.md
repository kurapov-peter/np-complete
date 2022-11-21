# Graph coloring problem
## Problem statement
Graph coloring is an assignment of label (color) for each vertex in graph such that no two adjacent vertices are of the same color. The problem is to find assignment with minimal colors required (this number is called *chromatic number*)  
**Applications**: scheduling, register allocation
### Greedy solution
Greedy coloring is iterating over all vertices in graph in some ordering and assigns first available color for current vertex (the first color that is not used in adjacent vertices; if all of them are used, we create new color). This alogithm has complexity *O(E)*, where *E* - number of edges (we check all adjacent vertices in each vertex, so the number of checks is *2 * E*). This approach doesn't guarantee that it will find the optimal coloring, but it can be prooved that for every graph there is a vertex ordering that gives an optimal solution with greedy algorithm. The problem of finding this ordering is itself NP-complete, but there is a simple heuristic that guarantees that number of colors will be no more than *d + 1*, where *d* - maximum vertex degree in this graph. This heuristic removes vertex with minimal degree from the graph and puts it in the end of requiried ordering, that process is repeated for leftover graph.
### DSatur solution
This algorithm has different ordering rule for vertices to be colored. It takes into account degree of saturation and first operates on vertex with the highest metric. This implementation operates in **O(n + m) log n** time, where **m** is the number of edges. Used *std::set* as red-black tree to order vertices. Also the containers of Graph have been modified for more appropriate access to Graph and Vertices. Overal it obtains better results then *Greedy algorithm* because of beter data accesses, but sagnificant boost observed on bipartite graphs, where it is designed to be better.

### Brute-force solution
Graph with *N* vertices can be colored with no more than N colors, so we look over all posible chromatic colors starting from 1 and check if graph can be colored with *k* colors by iterating over all possible colorings (*k^N*, where *N* - number of vertices). So in the worst case (chromatic color = *N*, e.g. complete graph) the complexity is *O(1^N + 2^N + ... + N^N)*.
## Report
CPU: i7-850H, 4.1 Ghz  

| Test        | DSatur, ns | Greedy, ns | Bruceforce, ns |
| ----------- | ------ | ------ | ---------- |
| Complete/1  | 76.5   | 91.3   | 6.11       |
| Complete/2  | 164    | 196    | 23.2       |
| Complete/3  | 324    | 371    | 181        |
| Complete/4  | 446    | 632    | 2686       |
| Complete/5  | 638    | 950    | 49547      |
| Complete/6  | 775    | 1401   | 900852     |
| Complete/7  | 889    | 1931   | 18337470   |
| Complete/8  | 1054   | 2474   | 443010162  |
| Acyclic/1   | 72.7   | 91.1   | 6.43       |
| Acyclic/2   | 165    | 202    | 23.9       |
| Acyclic/3   | 254    | 299    | 48.7       |
| Acyclic/4   | 293    | 423    | 90         |
| Acyclic/5   | 393    | 530    | 213        |
| Acyclic/6   | 370    | 696    | 563        |
| Acyclic/7   | 463    | 770    | 1704       |
| Acyclic/8   | 452    | 945    | 5078       |
| Bipartite/1 | 166    | 196    | 23.2       |
| Bipartite/2 | 354    | 493    | 62.2       |
| Bipartite/3 | 533    | 931    | 149        |
| Bipartite/4 | 763    | 1381   | 352        |
| Bipartite/5 | 986    | 2010   | 895        |
| Bipartite/6 | 1169   | 2708   | 2393       |
| Bipartite/7 | 1455   | 3573   | 6741       |
| Bipartite/8 | 1627   | 4593   | 19663      |
##
