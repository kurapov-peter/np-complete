#include "SSet.h"
#include <algorithm>
#include <iterator>

bool SSet::checkSumOptimized(DataType expected) {
	// TODO
	return true;
}

std::vector<int> subsetSums(std::vector<int> set)
{
        long total = 1<<set.size();    //total number of subsets = size of power set = 2^n
        std::vector<int> sums(total, 0);
    sums[1] = set[0];
    int effectiveBits = 1, prevPowOf2 = 1;
    for (long long i = 2; i < total; ++i)
    {
        if (i && (!(i&(i-1))))
        {
            ++effectiveBits;
            prevPowOf2 *= 2;
        }
        sums[i] = set[effectiveBits-1] + sums[i-prevPowOf2];
    }
    sums.erase(sums.begin());
    return sums;
}

bool SSet::checkSumOptimizedHS(DataType expected) {
	int half_size = set_.size() / 2;
	std::vector<DataType> firstpart(set_.begin(), set_.begin() + half_size);
	std::vector<DataType> secondpart(set_.begin() + half_size, set_.end());

	std::vector<DataType> firstlist = subsetSums(firstpart);
	std::vector<DataType> secondlist = subsetSums(secondpart);

        auto firstit = firstlist.begin();
        auto secondit = secondlist.begin();

	std::sort(firstlist.begin(), firstlist.end());
	std::sort(secondlist.begin(), secondlist.end());

	for(firstit = firstlist.begin(); firstit != firstlist.end(); firstit++) {
		for(secondit = secondlist.begin(); secondit != secondlist.end(); secondit++) {
			if ((*firstit==0)||(*secondit==0))
				return true;
        		int sum = *firstit + *secondit;
        		if (sum == expected)
            			return true;
    		}
	}
        return false;
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
