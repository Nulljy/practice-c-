#include <iostream>
#include <string>

using namespace std;
int main() {
	int t;
	while (true) {
		std::cin >> t;
		if (std::cin.fail()) { // fail�Լ�
			std::cout << "����� �Է����ּ���" << std::endl;
			std::cin.clear(); // �÷��� �ʱ�ȭ �Լ�
			std::cin.ignore(100, '\n'); // ignore�Լ�
		}
		if (t == 0) break;
		std::cout << "�Է� :: " << t << std::endl;
	}
	
	//while (std::cin >> t) {
	//	std::cout << "�Է� : " << t << std::endl; // 'c'�Է½� failbit�� on�Ǿ ������ 'c\n'�� �մ��� �ʰ� �����ع�����.
	//	if (t == 0) break; // ������ t�� int Ÿ���ε� 'c'�� char ���¶�
	//}
	return 0;
}