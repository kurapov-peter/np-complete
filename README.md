## Project
Implementation for np-complete subset sum problem solution  
Brute force, Horowitz&Sanhi and dynamic programming algorithms 

## Build
mkdir build && cd build  
cmake .. && make -j`nproc`  

## Functional testing
./tests/tests  
OR
cd tests && ctest -j`nproc`  

## Set generator
python3 tests/input_sets/set_generator.py <размер набора> <нижняя граница> <верхняя граница> > файл.txt

## Performance testing
TBD  
example: ./SAT/sat_bench  
         ./subset/bench_subset_BF    - brute force  
         ./subset/bench_subset_opt   - best optimized algorithm  
         ./subset/bench_subset_optHS - simple optimized algorithm
