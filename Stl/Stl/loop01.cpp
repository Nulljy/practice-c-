#include <iostream>
#include <vector>
// 범위 기반 for 문
template<typename T>
void print_vector(std::vector<T>& vec) {
	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
		std::cout << *itr << std::endl;
	}
}

template<typename T>
void print_vector_range_based(std::vector<T>& vec) {
	for (const auto& elem : vec) {
		std::cout << elem << std::endl;
	}
}

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	/*for (int elem : vec) {
		std::cout << "원소 : " << elem << std::endl;
	}*/
	print_vector_range_based(vec);
	return 0;
}