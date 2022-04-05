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

void move_and_reverse_stack(IntStack &src, IntStack &dst) {
	while (!src.IsEmpty()) {
		int ele = src.Top();
		dst.Push(ele);
		src.Pop();
	}
}

// 문제 A
void ReplaceItem(IntStack &s, int old_item, int new_item) {
	IntStack tmp;

	move_and_reverse_stack(s, tmp);
	while (!tmp.IsEmpty()) {
		int ele = tmp.Top();
		if (ele == old_item) {
			s.Push(new_item);
		}
		else {
			s.Push(ele);
		}
		tmp.Pop();
	}
}

void print_stack(IntStack &s) {
	IntStack tmp;

	copy_stack(s, tmp);
	while (!tmp.IsEmpty()) {
		std::cout << tmp.Top() << " ";
		tmp.Pop();
	}
	std::cout << "\n";
}

int main() {
	IntStack s;

	for (int i = 0; i < 30; i++) {
		s.Push(i % 10);
	}
	std::cout << "stack before replacing\n";
	print_stack(s);
	ReplaceItem(s, 4, 100);
	std::cout << "stack after replacing\n";
	print_stack(s);
}