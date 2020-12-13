# np-complete

## Prerequisites

Boost library is needed to build GraphColoring subproject.
In Linux boost library can be installed using package manager. For example, in Ubuntu

````bash
sudo apt install libboost-all-dev
````

Furthermore, a C++ compliler supporting C++20 coroutines is required to build the project. In Linux (Ubuntu) GCC 10 that has a support for coroutines enabled can be installed via

````bash
sudo apt install g++-10
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
