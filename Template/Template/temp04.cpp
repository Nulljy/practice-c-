#include <iostream>

// N ��ü ����
template<int N>
struct Int {
	static const int num = N;
};
// ���ϱ�
template<typename T,typename U>
struct add {
	typedef Int<T::num + U::num> result;
};


int main() {
	typedef Int<1> one;
	typedef Int<2> two;

	typedef add<one, two>::result three; // typedef�� ���ٸ� three::num���� ::num �տ� ���� ���Ѵ�. Ŭ���� / ����ü ���̾���Ѵ�.

	std::cout << three::num;

	return 0;
}