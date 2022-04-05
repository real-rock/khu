#include <iostream>
#include "StackTType.h"

typedef StackType<int> IntStack;

void copy_stack(IntStack &src, IntStack &dst) {
	IntStack tmp;

	while (!src.IsEmpty()) {
		int ele = src.Top();
		tmp.Push(ele);
		src.Pop();
	}
	while (!tmp.IsEmpty()) {
		int ele = tmp.Top();
		src.Push(ele);
		dst.Push(ele);
		tmp.Pop();
	}
}

void pop_and_print_stack(StackType<int> &s) {
	while (!s.IsEmpty()) {
		int top = s.Top();
		std::cout << top << " ";
		s.Pop();
	}
	std::cout << "\n";
}

int main() {
	IntStack test1, test2;

	for (int i = 0; i < 10; i++) {
		test1.Push(i);
	}
	copy_stack(test1, test2);
	std::cout << "test 1" << std::endl;
	pop_and_print_stack(test1);
	std::cout << "test 2" << std::endl;
	pop_and_print_stack(test2);
}