#include <iostream>
#include <sstream>

int main() {
	std::istringstream ss("123"); // istringstream�� ��ġ ���ڿ��� �ϳ��� ��Ʈ���̶� �����ϰ� ���ִ� ����ȭ ��ġ
	int x;
	ss >> x;

	std::cout << "�Է� ���� ������ :: " << x << std::endl;

	return 0;
}
