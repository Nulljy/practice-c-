#include <iostream>
#include <memory>

class Foo {
	int a, b;
public:
	Foo(int a, int b) : a(a), b(b) { std::cout << "생성자 호출\n"; }
	void print() { std::cout << "a : " << a << " b : " << b << std::endl; }
	~Foo() { std::cout << "소멸자 호출!\n"; }
};


int main() {
	std::unique_ptr<Foo> a(new Foo(3, 6));
	std::unique_ptr<Foo> ptr = std::make_unique<Foo>(3, 5);
	a->print();
	ptr->print();
}