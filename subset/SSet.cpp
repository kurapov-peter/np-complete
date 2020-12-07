#include "SSet.h"

bool SSet::checkSumOptimized(DataType expected) {
	// TODO
	return true;
}

bool SSet::checkSumSlow(DataType expected) {
	for (size_t i = 1; i <= set_.size(); i++) {
		if (checkSumOfNSlow(expected, i)) {
			return true;
		}
	}
	// Kept you waiting, huh?
	return false;
}


bool SSet::checkSumOfNSlow(DataType expected, size_t N) {
    std::vector<DataType> sub_set(N);
    return checkSumOfNRecursive(sub_set, expected, N, 0, 0);
}

/* data   ---> Temporary array to store current combination
   N      ---> Size of a combination to be checked
   index  ---> Current index in data
   i      ---> index of current element in set_     */
bool SSet::checkSumOfNRecursive(std::vector<DataType> data, DataType expected, size_t N, size_t index, size_t i)
{
    // Current cobination is ready, print it 
    if (index == N) {
        //for (int j = 0; j < r; j++)
        //    printf("%d ", data[j]);
        //printf("\n");
        return sumSet(data) == expected;
    }

    // When no more elements are there to put in data[] 
    if (i >= set_.size()) {
        return false;
    }

    // current is included, put next at next location 
    data[index] = set_[i];
    if (checkSumOfNRecursive(data, expected, N, index + 1, i + 1))
        return true;

    // current is excluded, replace it with next 
    // (Note that i+1 is passed, but index is not 
    // changed) 
    if (checkSumOfNRecursive(data, expected, N, index, i + 1))
        return true;
    return false;
}
