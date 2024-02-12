#include <iostream>
#include <string>

class Employee {
protected:
	// ����, ��å, �̸�, ��ũ
	int age;
	int rank;
	std::string name;
	std::string position;

public:
	Employee(int age, int rank, std::string name, std::string position) 
		: age(age), rank(rank), name(name), position(position) {};
	Employee(Employee& employee) {
		age = employee.age;
		rank = employee.rank;
		name = employee.name;
		position = employee.position;
	}

	Employee() {}

	virtual void print_info() {
		std::cout << name << "���� ���� ( age : " << age << ", position : " << position
			<< ") salary : " << caculate_pay() << "���� �Դϴ�.\n";
	}
	virtual int caculate_pay() { return 200 + 50 * rank; }
};

class Manager : public Employee {
	int year_of_service; // �Ŵ��� Ŭ������ �ʿ��� ����. �ټӳ���� ���߾� 5������ �߰�

public:
	Manager(int age, int rank, std::string name, std::string position, int year_of_service)
		: Employee(age, rank, name, position), year_of_service(year_of_service) {}
	Manager(Manager& manager) : Employee(manager.age, manager.rank, manager.name, manager.position) {
		year_of_service = manager.year_of_service;
	}
	Manager() : Employee() {}
	void print_info() override {
		std::cout << name << "���� ���� ( age : " << age << ", position : " << position << ") �ټ� ��� : " << year_of_service
			<< " salary : " << caculate_pay() << "���� �Դϴ�.\n";
	}
	int caculate_pay() override { return 200 + (50 * rank) + (5 * year_of_service); }
};

class Employee_list {
	int alloc_employee;
	int current_employee;
	Employee** employee_list;

public:
	Employee_list(int alloc_employee) : alloc_employee(alloc_employee) {
		current_employee = 0;
		employee_list = new Employee * [alloc_employee];
	}

	void add_employee(Employee* employee) {
		employee_list[current_employee] = employee;
		current_employee++;
	}

	int current_employee_num() { return current_employee; }

	void print_employee_info() {
		int total_pay = 0;
		for (int i = 0; i < current_employee; i++) {
			employee_list[i]->print_info();
			total_pay += employee_list[i]->caculate_pay();
		}
		std::cout << "�� ���: " << total_pay << "����" << std::endl;
	}
	~Employee_list() {
		for (int i = 0; i < current_employee; i++) {
			delete employee_list[i];
		}
		delete[] employee_list;
	}
};


int main() {
	Employee_list emp_list(10);
	emp_list.add_employee(new Employee(34, 1, "��ȫö", "����"));
	emp_list.add_employee(new Employee(34, 1, "����", "����"));
	emp_list.add_employee(new Employee(34, 2, "������", "�븮"));
	emp_list.add_employee(new Manager(41, 7, "���缮", "����", 12));
	emp_list.print_employee_info();
}