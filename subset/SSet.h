#ifndef SSET_H
#define SSET_H

#include <iostream>
#include <vector>



class SSet {
public:
	using DataType = int;

	void addElement(DataType elem) {
		set_.push_back(elem);
	}

	bool checkZeroSumSlow() {
		return checkSumSlow(0);
	}

	bool checkZeroSumOptimized() {
		return checkSumOptimized(0);
	}

	bool checkSumSlow(DataType expected);
	bool checkSumOptimized(DataType expected);

	void print() const {
		std::cout << "SSet: ";
		for (auto el : set_) {
			std::cout << el << " ";
		}
		std::cout << "\n";
	}

private:
	DataType sumSet(std::vector<DataType> set) {
		DataType sum = 0;
		for (auto el : set) {
			sum += el;
		}
		return sum;
	}

	bool checkSumOfNSlow(DataType expected, size_t N);
	bool checkSumOfNRecursive(std::vector<DataType> data, DataType expected, size_t N, size_t index, size_t i);

	std::vector<DataType> set_;
};


#endif // SSET_H