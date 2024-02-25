#include <iostream>
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

	std::vector<int>::iterator result = std::find(vec.begin(), vec.end(), 3); // findFunc01.cpp
	std::cout << "3 �� " << std::distance(vec.begin(), result) + 1 << " ��° ����\n";
}