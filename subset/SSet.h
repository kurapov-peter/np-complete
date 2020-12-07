#ifndef SSET_H
#define SSET_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>


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

	bool loadFromFile(std::string file_name) {
		std::ifstream input(file_name);

		if (input.is_open()) {
			size_t N;
			input >> N;
			set_ = std::vector<DataType>(N);
			for (size_t i = 0; i < N; i++) {
				input >> set_[i];
			}
			input.close();
			print();
			return true;
		}
		std::cout << "Failed to open file!\n";
		return false;
	}

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