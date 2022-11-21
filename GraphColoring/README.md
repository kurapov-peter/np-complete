# Graph coloring problem
## Problem statement
Graph coloring is an assignment of label (color) for each vertex in graph such that no two adjacent vertices are of the same color. The problem is to find assignment with minimal colors required (this number is called *chromatic number*)  
**Applications**: scheduling, register allocation
### Greedy solution
Greedy coloring is iterating over all vertices in graph in some ordering and assigns first available color for current vertex (the first color that is not used in adjacent vertices; if all of them are used, we create new color). This alogithm has complexity *O(E)*, where *E* - number of edges (we check all adjacent vertices in each vertex, so the number of checks is *2 * E*). This approach doesn't guarantee that it will find the optimal coloring, but it can be prooved that for every graph there is a vertex ordering that gives an optimal solution with greedy algorithm. The problem of finding this ordering is itself NP-complete, but there is a simple heuristic that guarantees that number of colors will be no more than *d + 1*, where *d* - maximum vertex degree in this graph. This heuristic removes vertex with minimal degree from the graph and puts it in the end of requiried ordering, that process is repeated for leftover graph.
### DSatur solution
This algorithm has different ordering rule for vertices to be colored. It takes into account degree of saturation and first operates on vertex with the highest metric. This implementation operates in **O(V + E) log V** time, where **E** is the number of edges. Used *std::set* as red-black tree to order vertices. Also the containers of Graph have been modified for more appropriate access to Graph and Vertices. Overal it obtains better results then *Greedy algorithm* because of better data accesses, I think.

### Brute-force solution
Graph with *N* vertices can be colored with no more than N colors, so we look over all posible chromatic colors starting from 1 and check if graph can be colored with *k* colors by iterating over all possible colorings (*k^N*, where *N* - number of vertices). So in the worst case (chromatic color = *N*, e.g. complete graph) the complexity is *O(1^N + 2^N + ... + N^N)*.
## Report
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
##
