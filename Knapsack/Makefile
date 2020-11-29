CXX=g++
TEST_SOURCES = knapsack.cpp main.cpp
TEST_FLAGS = -std=c++1z

CLANG=clang++
CLANG_FLGS = -std=c++17 -format -style=google -dump-config

all:
	$(CXX) $(TEST_FLAGS) -o main $(TEST_SOURCES)

style:
	$(CLANG) $(CLANG_FLAGS) -o main $(TEST_SOURCES)
	rm main
	
