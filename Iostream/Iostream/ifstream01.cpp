#include <fstream>
#include <iostream>
#include <string>

int main() {
	// ���� �б� �غ�
	std::ifstream in("test.txt");
	char buf[100];

	if (!in.is_open()) {
		std::cout << "�ش� txt�� �������� �ʽ��ϴ�.\n";
		return 0;
	}
	while (in) {
		in.getline(buf, 100); // '\n'�� ����ġ�� �ű���� buf�� ����
		std::cout << buf << std::endl;
	}
	
	return 0;
}