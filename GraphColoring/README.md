# Graph coloring problem
## Problem statement
Graph coloring is an assignment of label (color) for each vertex in graph such that no two adjacent vertices are of the same color. The problem is to find assignment with minimal colors required (this number is called *chromatic number*)  
**Applications**: scheduling, register allocation
### Greedy solution
Greedy coloring is iterating over all vertices in graph in some ordering and assigns first available color for current vertex (the first color that is not used in adjacent vertices; if all of them are used, we create new color). This alogithm has complexity *O(E)*, where *E* - number of edges (we check all adjacent vertices in each vertex, so the number of checks is *2 * E*). This approach doesn't guarantee that it will find the optimal coloring, but it can be prooved that for every graph there is a vertex ordering that gives an optimal solution with greedy algorithm. The problem of finding this ordering is itself NP-complete, but there is a simple heuristic that guarantees that number of colors will be no more than *d + 1*, where *d* - maximum vertex degree in this graph. This heuristic removes vertex with minimal degree from the graph and puts it in the end of requiried ordering, that process is repeated for leftover graph.
### Brute-force solution
Graph with *N* vertices can be colored with no more than N colors, so we look over all posible chromatic colors starting from 1 and check if graph can be colored with *k* colors by iterating over all possible colorings (*k^N*, where *N* - number of vertices). So in the worst case (chromatic color = *N*, e.g. complete graph) the complexity is *O(1^N + 2^N + ... + N^N)*.
## Report
CPU: i7-10700, 4.8 Ghz  

Coloring of complete graph:  
| Graph size | Greedy, ns | Brute-force, ns |
|------------|------------|-----------------|
| 1          | 68         | 3               |
| 2          | 166        | 12              |
| 3          | 316        | 117             |
| 4          | 540        | 1893            |
| 5          | 840        | 38437           |
| 6          | 1255       | 709094          |
| 7          | 1651       | 15567125        |
| 8          | 2169       | 375370570       |
| 9          | 2704       | 9520096563      |
| 10         | 3383       | 280862473187    |

Coloring of acyclic graph (tree):  
| Graph size | Greedy, ns | Brute-force, ns |
|------------|------------|-----------------|
| 1          | 68         | 3               |
| 2          | 166        | 12              |
| 3          | 253        | 28              |
| 4          | 350        | 60              |
| 5          | 422        | 146             |
| 6          | 544        | 370             |
| 7          | 629        | 1070            |
| 8          | 791        | 3288            |
| 9          | 873        | 9688            |
| 10         | 987        | 28742           |

Coloring of bipartite graph:
| Graph partition size | Greedy, ns | Brute-force, ns |
|----------------------|------------|-----------------|
| 1                    | 165        | 12              |
| 2                    | 403        | 41              |
| 3                    | 734        | 112             |
| 4                    | 1179       | 259             |
| 5                    | 1764       | 621             |
| 6                    | 2378       | 1663            |
| 7                    | 3100       | 4651            |
| 8                    | 3901       | 13345           |
| 9                    | 4899       | 39129           |
| 10                   | 5937       | 119386          |
