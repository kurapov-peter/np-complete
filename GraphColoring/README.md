# Graph coloring problem
## Problem statement
Graph coloring is an assignment of label (color) for each vertex in graph such that no two adjacent vertices are of the same color. The problem is to find assignment with minimal colors required (this number is called *chromatic number*)  
**Applications**: scheduling, register allocation
### Greedy solution
Greedy coloring is iterating over all vertices in graph in some ordering and assigns first available color for current vertex (the first color that is not used in adjacent vertices; if all of them are used, we create new color). This alogithm has complexity *O(E)*, where *E* - number of edges (we check all adjacent vertices in each vertex, so the number of checks is *2 * E*). This approach doesn't guarantee that it will find the optimal coloring, but it can be prooved that for every graph there is a vertex ordering that gives an optimal solution with greedy algorithm. The problem of finding this ordering is itself NP-complete, but there is a simple heuristic that guarantees that number of colors will be no more than *d + 1*, where *d* - maximum vertex degree in this graph. This heuristic removes vertex with minimal degree from the graph and puts it in the end of requiried ordering, that process is repeated for leftover graph.
### DSatur solution
This algorithm has different ordering rule for vertices to be colored. It takes into account degree of saturation and first operates on vertex with the highest metric. This implementation operates in **O(V + E) log V** time, where **E** is the number of edges. Used *std::set* as red-black tree to order vertices. Also the containers of Graph have been modified for more appropriate access to Graph and Vertices. Overal it obtains better results then *Greedy algorithm* because of better data accesses, I think.
### Johns-Plassmann solution
This algorithm operates by iteratively finding independent sets and assigning same color to those sets. Algorithm that finds independent sets as well as color assignation can be parallelized. Complexity is **O(V) log V**, if number of steps is considered logarithmic of number of vertices(which seems to be true). This implementation produces slightly worse results as algos using heuristics, because independent sets are constructed based on random values and does not analyse topology of graph. On multicore system it is expected to produce better time perf, but on single-threaded it is generally performs on level of greedy algo implementation.
### Brute-force solution
Graph with *N* vertices can be colored with no more than N colors, so we look over all posible chromatic colors starting from 1 and check if graph can be colored with *k* colors by iterating over all possible colorings (*k^N*, where *N* - number of vertices). So in the worst case (chromatic color = *N*, e.g. complete graph) the complexity is *O(1^N + 2^N + ... + N^N)*.
## Report
CPU: i5-10400F, 4.0 Ghz

| Test        | DSatur, ns | Greedy, ns | John-Plassmann, ns | Bruceforce, ns |
| ----------- |------------|------------|--------------------|----------------|
| Complete/1  | 66         | 74.2       | 62.7               | 3.66           |
| Complete/2  | 158        | 182        | 166                | 13.3           |
| Complete/3  | 321        | 357        | 333                | 133            |
| Complete/4  | 554        | 602        | 557                | 2246           |
| Complete/5  | 850        | 915        | 853                | 44540          |
| Complete/6  | 1216       | 1322       | 1233               | 858995         |
| Complete/7  | 1704       | 1820       | 1722               | 18096156       |
| Complete/8  | 2267       | 2437       | 2322               | 439698140      |
| Acyclic/1   | 65.2       | 75         | 62.7               | 3.66           |
| Acyclic/2   | 160        | 182        | 166                | 13.4           |
| Acyclic/3   | 262        | 281        | 267                | 34.8           |
| Acyclic/4   | 352        | 399        | 399                | 69.2           |
| Acyclic/5   | 474        | 484        | 527                | 163            |
| Acyclic/6   | 574        | 631        | 642                | 419            |
| Acyclic/7   | 663        | 716        | 736                | 1327           |
| Acyclic/8   | 768        | 933        | 899                | 3804           |
| Bipartite/1 | 159        | 185        | 167                | 14             |
| Bipartite/2 | 396        | 455        | 409                | 50             |
| Bipartite/3 | 748        | 816        | 784                | 144            |
| Bipartite/4 | 1212       | 1315       | 1218               | 297            |
| Bipartite/5 | 1870       | 1971       | 1747               | 735            |
| Bipartite/6 | 2509       | 2639       | 2356               | 1935           |
| Bipartite/7 | 3272       | 3455       | 3129               | 5481           |
| Bipartite/8 | 4224       | 4316       | 3920               | 15266          |
##
