# Hamiltonian Path Problem
## Problem statement
For a given directed unweighted graph, it is
required to determine whether a hamiltonian path
exists in it and, if it exists, to display it.
## Input format
The first line contains two positive numbers
*n* and *m*, where *n* is graph vertices number
and *m* is graph edges number.
Next *m* lines define edges and contain two positive
numbers *v_out* and *v_in* not exceeding *n*,
where *v_out* is vertex that the edge emanates
and *v_in* is vertex that the edge enters.
## Output format
In case hamiltonian path exists in the graph, program
prints out the message: *"Solution exists!*
*Hamiltonian path is: v_1 -> v_2 -> ... -> v_n"*,
and *"Solution does not exist!"* otherwise.
## How to build
Requirements to build and run are CMake version 3.16 and C++ 17
### Build and run Brute Force solver
```
cd np-complete
mkdir build && cd build
cmake .. && make -j NPROCS
HamiltonianPathProblem/hamiltonian_path_bf_bench < your_test.txt
```
### Build and run Dynamic Programming solver
```
cd np-complete
mkdir build && cd build
cmake .. && make -j NPROCS
HamiltonianPathProblem/hamiltonian_path_dp_bench < your_test.txt
```
### Build and run Graph tests
```
cd np-complete
mkdir build && cd build
cmake .. && make -j NPROCS
tests/run_graph_test
```
### Build and run Brute Force solver benchmarks
```
cd np-complete
mkdir build && cd build
cmake .. && make -j NPROCS
tests/run_hamiltonian_path_brute_force_test
```
### Build and run Dynamic Programming solver benchmarks
```
cd np-complete
mkdir build && cd build
cmake .. && make -j NPROCS
tests/run_hamiltonian_path_dp_test
```
## Report
### Brute force algorithm description
The idea of the algorithm is to go over all possible graph paths, checking vertices
connectivity, until Hamiltonian one is found.

Time complexity is O(n * n!), memory is O(n).
### Dynamic programming algorithm description
For every subset *S* of vertices check whether there is a path that visits
"EACH and ONLY" the vertices in *S* exactly once and ends at a vertex *v*.
Do this for all *v* included in *S*. A path exists that visits each vertex in
subset *S* and ends at vertex *v* that is included into *S* if *v* has a neighbor
*w* in *S* and there is a path that visits each vertex in set *S-{v}* exactly once
and ends at *w*. If there is such a path, then adding the edge *w-v* to it will
extend it to visit *v* and as it is already visiting every vertex in *S-{v}*, so
the new path will visit every vertex in *S*.

Time complexity is O(n^2 * 2^n), memory is O(n * 2^n).
### Benchmarks description
We estimated performance on 3 benchmarks families:
* *Consistent graphs with solution* is *n* vertices
connected one-by-one, i.e. 1 -> 2 -> ... -> n
* *Consistent graphs without solution* is *n - 1*
vertices connected one-by-one ans *n*-th vertex
isolated, i.e. 1 -> 2 -> ... -> n-1; n
* *Fully connected graph without solution* is *n - 1*
fully connected vertices and *n*-th vertex isolated
### Performance estimation results
* *Consistent graphs with solution*
![Consistent With Solution Performance](https://github.com/DandyForever/np-complete/blob/master/HamiltonianPathProblem/Report/consistent_with_solution_chart.PNG?raw=True)
* *Consistent graphs without solution*
![Consistent Without Solution Performance](https://github.com/DandyForever/np-complete/blob/master/HamiltonianPathProblem/Report/consistent_without_solution_chart.PNG?raw=True)
* *Fully connected graph without solution*
![Fully Connected Without Solution Performance](https://github.com/DandyForever/np-complete/blob/master/HamiltonianPathProblem/Report/Fully_connected_without_solution.PNG?raw=True)
### Conclusion
* Brute force solution works efficiently on strongly degenerate graphs with the number of edges m ~ number of vertices
n, but it slows down a lot in general case with m ~ n^2, which can be seen from the results on fully connected graphs
  (13 vertex fully connected graph calculates more than 10 minutes)
* Dynamic programming solution works stable in any case of graph's edges and more effective than
Brute Force solution in general case