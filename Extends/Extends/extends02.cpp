#include <iostream>

class Base {
	std::string s;

public:
	Base() : s("기반") { std::cout << "기반 클래스의 what()" << std::endl; }

	virtual void what() { std::cout << s << std::endl; }
};

class Derived : public Base {
	std::string s;

public:
	Derived() : Base(), s("파생") {
		std::cout << "파생 클래스의 what()" << std::endl;

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

	std::cout << " == 실제 객체는 BASE == \n";
	p_p->what();
	std::cout << " == 실제 객체는 Derived == \n";
	p_c->what();
	return 0;
}