#include <iostream>
#include <list>

// 리스트
// 리스트의 경우 []나 at이 없다. 하지만 임의의 위치에 원소를 추가하거나 제거하는 작업이 O(1)으로 매우 빠르다.
// 이유는 원하는 위치 앞과 뒤에 있는 링크 값만 바꿔주면 되기 때문이다.

/*
	재밌는 점은 리스트의 반복자의 경우 ++나 --밖에 사용하지 못한다는 점이다.
*/

template<typename T> // list 출력 만들기
void print_tl(std::list<T>& lst) {
	std::cout << "[ ";
	for (const auto& elem : lst) {
		std::cout << elem << " ";
	}
	std::cout << "]\n";
}

int main() {
	std::list<int> lst;

	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);

	print_tl(lst);

	for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
		if (*itr == 20) {
			lst.insert(itr, 50);
		}
	}

	std::cout << "값이 20 인 원소 앞에 50을 추가\n";
	print_tl(lst);

	for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
		if (*itr == 30) {
			lst.erase(itr);
			break;
		}
	}

	std::cout << "값이 30인 원소를 제거\n";
	print_tl(lst);

	return 0;
}