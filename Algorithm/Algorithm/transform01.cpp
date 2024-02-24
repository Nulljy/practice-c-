#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template<typename Iter>
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
	std::cout << "처음vec 상태------" << std::endl;
	std::sort(vec.begin(), vec.end());
	print(vec.begin(), vec.end());

	std::cout << "벡터전체에1 을더한다" << std::endl;
	std::transform(vec.begin(), vec.end(), vec.begin(),
		[](int i) {return i + 1; }); // transform01
	print(vec.begin(), vec.end());
}