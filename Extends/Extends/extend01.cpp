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

class EmployeeList {

private:
	int alloc_employee;
	int current_employee;
	Employee** employee_list;

public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
		employee_list = new Employee * [alloc_employee];
		current_employee = 0;
	}

	void add_employee(Employee* employee) {
		employee_list[current_employee] = employee;
		current_employee++;
	}

	// 현재 고용자 숫자 출력
	int current_employee_num() {
		return current_employee;
	}
	// 고용인 정보 출력, 토탈 비용 출력
	void print_employee_info() {
		int total_price = 0;
		for (int i = 0; i < current_employee; i++) {
			employee_list[i]->print();
			total_price += employee_list[i]->calculate_pay();
		}
		std::cout << "총 비용: " << total_price << "만원\n";
	}

	~EmployeeList() {
		for (int i = 0; i < current_employee; i++) {
			delete[] employee_list[i];
		}
		delete[] employee_list;
	}
};


int main() {
	EmployeeList emp_list(10);
	emp_list.add_employee(new Employee(34, 1, "노홍철", "평사원"));
	emp_list.add_employee(new Employee(34, 1, "하하", "평사원"));

	emp_list.add_employee(new Employee(41, 7, "유재석", "부장"));
	emp_list.add_employee(new Employee(43, 4, "정준하", "과장"));
	emp_list.add_employee(new Employee(43, 5, "박명수", "차장"));
	emp_list.print_employee_info();
	return 0;
}