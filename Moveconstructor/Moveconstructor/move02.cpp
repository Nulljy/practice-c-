#include <iostream>
#include <utility>

class A {
public:
	A() { std::cout << "������ ȣ��\n"; }
	A(A& a) { std::cout << "���� ������ ȣ��\n"; }
	A(A&& a) { std::cout << "�̵� ������ ȣ��\n"; }
};

int main() {
	A a;
	A a1(a);
	A a2(std::move(a));
}