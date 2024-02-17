#include <iostream>
#include <array>
#include <algorithm>



template <typename T> // after using default constructor
struct Compare {
	bool operator()(const T& a, const T& b) const { return a < b; } // a < b  a가 b보다 작은게 트루면 트루
};

template<typename T, typename Comp = Compare<T>>
T Min(T a, T b) {
	Comp comp;
	if (comp(a, b)) {
		return a;
	}
	return b;
}

int main() {
	int a = 3, b = 4;
	char a1 = 'c';
	char a2 = 'a';

	std::cout << "min : " << Min(a, b) << std::endl;
}