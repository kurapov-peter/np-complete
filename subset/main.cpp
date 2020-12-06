#include "SSet.h"
#include <iostream>


void addFromInput(SSet &set) {
	SSet::DataType elem;
	std::cin >> elem;
	set.addElement(elem);
}

int main(int argc, char* argv[]) {
//	if (argc > 1 && !strcmp(argv[1], "test")) {
//		std::cout << "tests:\n";
		//runTests();
//	}
//	else if (argc > 2 && !strcmp(argv[1], "file")) {
//		std::cout << "Run from file: " << argv[2] << "\n";
		//runFromFile(argc[2]);
//	}
//	else
//	{
		SSet set;
		int N;
		std::cin >> N;
		if (N > 1) {
			for (int i = 0; i < N; i++) {
				addFromInput(set);
			}

			set.print();
			set.checkZeroSumSlow();
		}
//	}
	return 0;
}
