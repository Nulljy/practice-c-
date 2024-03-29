#include <functional>
#include <iostream>
#include <string>

class A {
	int c;
public:
	A(int c) : c(c) {}
	int some_func() {
		std::cout << "비상수 함수: " << ++c << std::endl;
		return c;
	}

	int some_const_function() const {
		std::cout << "상수 함수: " << c << std::endl;
		return c;
	}

	static void st(){}
};

int main() {
	A a(5);
	std::function<int(A&)> f1 = &A::some_func; // 멤버함수들은 구현 상 자신을 호출한 객체를 인자로 암묵적으로 받고있었음
	std::function<int(const A&)> f2 = &A::some_const_function;

	f2(a);
	f1(a);
}