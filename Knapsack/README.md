# Knapsack

`BruteForce` and `BranchAndBound` implemetation of knapsack problem.

## Build

mkdir build && cd build  
cmake .. && make -j`nproc`  

## Fuctional testing

cd build/tests/  
./knapsack_test  

## Perfomace testing

cd build/knapsack/  
./bench  


## Results of perfomance testing 

Device: Intel(R) Core(TM) i7-6500U CPU @ 2.50GHz  
  
 
BruteForce_10        :  114332 ns       
BranchAndBound_10    :  30388 ns      
BruteForce_15        :  5229265 ns    
BranchAndBound_15    :  110226 ns      
BruteForce_20        :  203160575 ns    
BranchAndBound_20    :  360968 ns       
BruteForce_25        :  7618288950 ns   
BranchAndBound_25    :  2135664 ns      
