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
		std::cout << name << " ( " << position << ", " << age << " ) ==> " << calculate_pay() << " ����\n";
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

	// ���� ����� ���� ���
	int current_employee_num() {
		return current_employee;
	}
	// ����� ���� ���, ��Ż ��� ���
	void print_employee_info() {
		int total_price = 0;
		for (int i = 0; i < current_employee; i++) {
			employee_list[i]->print();
			total_price += employee_list[i]->calculate_pay();
		}
		std::cout << "�� ���: " << total_price << "����\n";
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
	emp_list.add_employee(new Employee(34, 1, "��ȫö", "����"));
	emp_list.add_employee(new Employee(34, 1, "����", "����"));

	emp_list.add_employee(new Employee(41, 7, "���缮", "����"));
	emp_list.add_employee(new Employee(43, 4, "������", "����"));
	emp_list.add_employee(new Employee(43, 5, "�ڸ��", "����"));
	emp_list.print_employee_info();
	return 0;
}