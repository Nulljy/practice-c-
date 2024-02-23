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
//struct int_compare { // 함수 객체
//	bool operator()(const int& a, const int& b) const { return a > b; } // 이 경우 int, string 만들어야함
//};
template<typename T>
struct greater_comp {
	bool operator()(const T& a, const T& b) const { return a > b; }// 그래서 greater_comp 사용, operator>가 있어야함
};


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
	//std::sort(vec.begin(), vec.end(), int_compare()); // sort02.cpp
	std::sort(vec.begin(), vec.end(), greater_comp<int>()); // sort02.cpp

	print(vec.begin(), vec.end());

	return 0;
}
