#include <iostream>

/*
	std::cout
	std::endl
	1. ����(char) �� ������ ���ڿ� ����, C ���ڿ� (char *) �� ������ ����
	2. ���ڿ� ���̸� ���ϴ� �Լ�
	3. ���ڿ� �ڿ� �ٸ� ���ڿ� ���̱�
	4. ���ڿ� ���� ���ԵǾ� �ִ� ���ڿ� ���ϱ�
	5. ���ڿ��� ������ ��
	6. ���ڿ� ũ�� �� (���� ��)
*/
int getLength(char* text);

class MyString {
private:
	char* string;
	int length;

public:
	MyString(char* text){};
	int GetLeng() {};

};

MyString::MyString(char* text) {
	length = getLength(text);
	strncpy_s(string, sizeof(length), text, length);
	string[length] = '\n';
}



int getLength(char* text) {
	char* tmp1 = text;
	int leng = 0;
	while (*tmp1 != NULL) {
		tmp1++;
		leng++;
	}
	return leng;
}

int main() {
	return 0;
}