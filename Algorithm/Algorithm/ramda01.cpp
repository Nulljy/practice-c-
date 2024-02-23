#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
	while (begin != end) {
		std::cout << "[" << *begin << "] ";
		begin++;
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	std::cout << "처음\n";
	print(vec.begin(), vec.end());

	std::cout << "람다 사용하여 홀수인 원소 제거\n";
	//vec.erase(std::remove_if(vec.begin(), vec.end(),
	//	[](int i) -> bool {return i % 2 == 1; }), vec.end()); // ramda01.cpp 람다 함수
	int num_erased = 0;
	vec.erase(std::remove_if(vec.begin(), vec.end(),
		[&num_erased](int i) -> bool {
			if (num_erased >= 2) {
				return false;
			}
			else if (i % 2 == 1) {
				num_erased++;
				return true;
			}
			return false;
		}), vec.end());
	print(vec.begin(), vec.end());
	return 0;
}