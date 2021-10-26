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