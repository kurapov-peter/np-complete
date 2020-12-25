 ## Build
mkdir build && cd build  
cmake .. && make -j`nproc`  

## Functional testing
./tests/tests  
OR  
cd tests && ctest -j`nproc`  


## Performance testing
./SAT/sat_bench  
./subset/bench_subset_BF    - brute force  
./subset/bench_subset_opt   - best optimized algorithm  
./subset/bench_subset_optHS - simple optimized algorithm
