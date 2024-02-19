#include <iostream>

// N 객체 생성
template<int N>
struct Int {
	static const int num = N;
};
// 더하기
template<typename T,typename U>
struct add {
	typedef Int<T::num + U::num> result;
};


int main() {
	typedef Int<1> one;
	typedef Int<2> two;

	typedef add<one, two>::result three; // typedef가 없다면 three::num에서 ::num 앞에 쓰지 못한다. 클래스 / 구조체 등이어야한다.

	std::cout << three::num;

	return 0;
}