#include <iostream>

class Base {
public:
	std::string parent_string;
	Base() : parent_string("���") { std::cout << "��� Ŭ����" << std::endl; }
	void what() { std::cout << parent_string << std::endl; }
};

class Derived : public Base {
	std::string child_string;

public:
	Derived() : Base(), child_string("�Ļ�") {
		std::cout << "�Ļ� Ŭ����" << std::endl;

		parent_string = "�ٲٱ�";
	}

	void what() { std::cout << child_string << std::endl; }
};

int main() {
	Base p;
	std::cout << p.parent_string << std::endl;

	Derived c;
	std::cout << c.parent_string << std::endl;
	return 0;
}