#include <iostream>
#include "DoubleStack.h"

int main() {
	DoubleStack<int> test1;
	int test_case[10] = {
		1, 5, 1000, 10001, 100413, 88, 5000, 2323, 999, 0
	};

	for (int i = 0; i < 10; i++) {
		test1.Push(test_case[i]);
	}
	test1.Print();
}