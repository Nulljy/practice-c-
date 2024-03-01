#include <iostream>
#include <memory>

class Foo {
	int a, b;
public:
	Foo(int a, int b) : a(a), b(b) { std::cout << "������ ȣ��\n"; }
	void print() { std::cout << "a : " << a << " b : " << b << std::endl; }
	~Foo() { std::cout << "�Ҹ��� ȣ��!\n"; }
};


int main() {
	std::unique_ptr<Foo> a(new Foo(3, 6));
	std::unique_ptr<Foo> ptr = std::make_unique<Foo>(3, 5);
	a->print();
	ptr->print();
}