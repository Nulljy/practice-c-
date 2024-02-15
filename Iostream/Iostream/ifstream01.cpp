#include <fstream>
#include <iostream>
#include <string>

int main() {
	// ���� �б� �غ�
	std::ifstream in("test.txt", std::ios::binary);
	std::string s = "";

	if (in.is_open()) {
		//��ġ �����ڸ� ���� ������ �ű��.
		in.seekg(0, std::ios::end);

		// �� ��ġ�� �д´�.
		int size = in.tellg();

		// �� ũ���� ���ڿ��� �Ҵ�
		s.resize(size);

		// ��ġ �����ڸ� �ٽ� ���� �� ������ �ű��.
		in.seekg(0, std::ios::beg);

		// ���� ��ü ������ �о ���ڿ��� ����
		in.read(&s[0], size);
		std::cout << s << std::endl;
	}
	else {
		std::cout << "������ ã�� �� �����ϴ�.\n";
	}
	return 0;
}