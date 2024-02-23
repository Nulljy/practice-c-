#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

template<typename Itr>
void print(Itr begin, Itr end) {
	while (begin != end) {
		std::cout << "[ " << *begin << " ] ";
		begin++;
	}
	std::cout << std::endl;
}

struct is_odd {
	bool operator()(const int& i) { return i % 2 == 1; }
};

int main() {
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	std::cout << "처음 vec 상태" << std::endl;
	print(vec.begin(), vec.end());

	////remove
	//vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end()); // remove 인자: [시작, 끝, 지울val]
	vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd()), vec.end());
	print(vec.begin(), vec.end());

	return 0;
}