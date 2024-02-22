#include <iostream>
#include <list>

// ����Ʈ
// ����Ʈ�� ��� []�� at�� ����. ������ ������ ��ġ�� ���Ҹ� �߰��ϰų� �����ϴ� �۾��� O(1)���� �ſ� ������.
// ������ ���ϴ� ��ġ �հ� �ڿ� �ִ� ��ũ ���� �ٲ��ָ� �Ǳ� �����̴�.

/*
	��մ� ���� ����Ʈ�� �ݺ����� ��� ++�� --�ۿ� ������� ���Ѵٴ� ���̴�.
*/

template<typename T> // list ��� �����
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

	std::cout << "���� 20 �� ���� �տ� 50�� �߰�\n";
	print_tl(lst);

	for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
		if (*itr == 30) {
			lst.erase(itr);
			break;
		}
	}

	std::cout << "���� 30�� ���Ҹ� ����\n";
	print_tl(lst);

	return 0;
}