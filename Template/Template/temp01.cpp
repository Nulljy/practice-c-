#include <iostream>
#include <array>

template <typename T> // 타입이 아닌 템플릿 인자
void print_array(const T& arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
	std::array<int, 7> arr1 = { 1, 2, 3, 4, 5, 6, 7 };

	print_array(arr);
	print_array(arr1);


	return 0;
}