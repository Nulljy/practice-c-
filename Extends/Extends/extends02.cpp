#include <iostream>

class Base {
	std::string s;

public:
	Base() : s("���") { std::cout << "��� Ŭ������ what()" << std::endl; }

	virtual void what() { std::cout << s << std::endl; }
};

class Derived : public Base {
	std::string s;

public:
	Derived() : Base(), s("�Ļ�") {
		std::cout << "�Ļ� Ŭ������ what()" << std::endl;

		what();
	}
	void what() {
		std::cout << s << std::endl;
	}
};

int main() {
	Base p;
	Derived c;

	Base* p_c = &c;
	Base* p_p = &p;

	std::cout << " == ���� ��ü�� BASE == \n";
	p_p->what();
	std::cout << " == ���� ��ü�� Derived == \n";
	p_c->what();
	return 0;
}