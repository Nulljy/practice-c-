#include <iostream>
#include <vector>
#include <algorithm>

// partial_sort
template<typename Iter>
void print(Iter begin, Iter end) {
	while (begin != end) {
		std::cout << *begin << " ";
		begin++;
	}
	std::cout << std::endl;
}
//struct int_compare { // �Լ� ��ü
//	bool operator()(const int& a, const int& b) const { return a > b; } // �� ��� int, string ��������
//};
template<typename T>
struct greater_comp {
	bool operator()(const T& a, const T& b) const { return a > b; }// �׷��� greater_comp ���, operator>�� �־����
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
	//std::sort(vec.begin(), vec.end(), greater_comp<int>()); // sort02.cpp
	std::partial_sort(vec.begin(), vec.begin() + 3, vec.end()); // sort03.cpp partial_sort

	print(vec.begin(), vec.end());

	return 0;
}
