#include <iostream>

class Employee {
private:
	int age;
	int rank;
	std::string name;
	std::string position;

public:
	Employee(int age, int rank, std::string name, std::string position)
		: age(age), rank(rank), name(name), position(position) {};
	Employee(Employee& a) 
		: age(a.age), rank(a.rank), name(a.name), position(a.position) {};

	//default creator
	Employee() {};

	void print() {
		std::cout << name << " ( " << position << ", " << age << " ) ==> " << calculate_pay() << " 만원\n";
	}

	int calculate_pay() {
		return 200 + rank * 50;
	}
};


int main() {
	Employee a(21, 2, "진", "신입");
	Employee b(a);
	a.print();
	b.print();
	return 0;
}