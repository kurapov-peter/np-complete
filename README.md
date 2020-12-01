# np-complete

## Prerequisites

Boost library is needed to build GraphColoring subproject.
In Linux boost library can be installed using package manager. For example, in Ubuntu

````bash
sudo apt install libboost-all-dev
````

## Build
mkdir build && cd build  
cmake .. && make -j`nproc`  

## Functional testing
./tests/tests  
OR
cd tests && ctest -j`nproc`  


## Performance testing
TBD  
example: ./SAT/sat_bench