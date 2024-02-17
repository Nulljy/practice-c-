#include <iostream>

template <typename T, int num> // 타입이 아닌 템플릿 인자
T add_num(T t) {
	return t + num;
}
int main() {
	int a = add_num<int, 5>(4);
	std::cout << a << std::endl;
	return 0;
}