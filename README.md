# np-complete

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