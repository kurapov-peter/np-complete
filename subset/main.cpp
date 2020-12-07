#include "SSet.h"
#include <iostream>


void addFromInput(SSet &set) {
	SSet::DataType elem;
	std::cin >> elem;
	set.addElement(elem);
}

int main(int argc, char* argv[]) {
	SSet set;
	if (argc > 1) {
		set.loadFromFile(argv[1]);
		set.checkZeroSumSlow();
	} else {
		size_t N;
		std::cin >> N;
		if (N > 1) {
			for (size_t i = 0; i < N; i++) {
				addFromInput(set);
			}
			set.print();
			set.checkZeroSumSlow();
		}
	}

	return 0;
}
