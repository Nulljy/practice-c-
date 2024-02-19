#include <iostream>

template<int X, int Y> // 함수로 치면 매개변수 뭐 들어갈건지
struct GCD { // 함수 이름처럼 생각
	static const int value = GCD<Y, X% Y>::value; // 재귀함수의 형태
};

template<int X>
struct GCD<X, 0> { // 재귀 끝 조건
	static const int value = X; // 재귀 끝나고 리턴값으로 생각하면 될듯
};


int main() {
	const int a = 15;
	const int b = 12; // 12, 3 = 0 따라서 3
	std::cout << a << "와 " << b << "의 최대 공약수는 " << GCD<a, b>::value;

	return 0;
}