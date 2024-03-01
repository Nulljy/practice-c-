#include <functional>
#include <iostream>
#include <string>

class A {
	int c;
public:
	A(int c) : c(c) {}
	int some_func() {
		std::cout << "���� �Լ�: " << ++c << std::endl;
		return c;
	}

	int some_const_function() const {
		std::cout << "��� �Լ�: " << c << std::endl;
		return c;
	}

	static void st(){}
};

int main() {
	A a(5);
	std::function<int(A&)> f1 = &A::some_func; // ����Լ����� ���� �� �ڽ��� ȣ���� ��ü�� ���ڷ� �Ϲ������� �ް��־���
	std::function<int(const A&)> f2 = &A::some_const_function;

	f2(a);
	f1(a);
}