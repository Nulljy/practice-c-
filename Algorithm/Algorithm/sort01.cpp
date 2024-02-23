#include <iostream>
#include <vector>
#include <algorithm>

// sort 사용, template로 매개인자를 원하는 클래스 넣어주기
template<typename Iter>
void print(Iter begin, Iter end) {
	while (begin != end) {
		std::cout << *begin << " ";
		begin++;
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(6);
	vec.push_back(4);
	vec.push_back(7);
	vec.push_back(2);

	print(vec.begin(), vec.end());
	std::sort(vec.begin(), vec.end());

	print(vec.begin(), vec.end());

	return 0;
}
