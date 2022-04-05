#include <iostream>

using namespace std;

typedef char String[9];

struct StudentRecord {
	String first_name;
	String last_name;
	int id;
	float gpa;
	int current_hours;
	int total_hours;
};

int main(void) {
	StudentRecord students[100];
	cout << sizeof(StudentRecord) << endl;
	cout << sizeof(students) << endl;
	return 0;
}