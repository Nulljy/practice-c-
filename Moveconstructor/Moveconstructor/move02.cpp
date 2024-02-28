#include <iostream>
#include <utility>

class A {
public:
	A() { std::cout << "생성자 호출\n"; }
	A(A& a) { std::cout << "복사 생성자 호출\n"; }
	A(A&& a) { std::cout << "이동 생성자 호출\n"; }
};

int main() {
	A a;
	A a1(a);
	A a2(std::move(a));
}