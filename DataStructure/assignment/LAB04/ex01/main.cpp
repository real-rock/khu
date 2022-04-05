#include <iostream>
#include "StackTType.h"

void input_data(StackType<int> &s) {
	for (int i = 1; i <= 6; i++) {
		s.Push(i);
	}
}

void pop_and_print_stack(StackType<int> &s) {
	while (!s.IsEmpty()) {
		int top = s.Top();
		std::cout << top << "\n";
		s.Pop();
	}
}

int main() {
	StackType<int> s;

	input_data(s);
	pop_and_print_stack(s);
	return 0;
}
