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
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);
	~MyString();
	void print();
	void println();

};

MyString::MyString(char c) {
	string = new char[2];
	string[0] = c;
	string[1] = '\0';
	length = 1;
	std::cout << string << std::endl;
}

MyString::MyString(const char* str) {
	length = strlen(str);
	string = new char[length+1];
	for (int i = 0; i < length; i++) {
		string[i] = str[i];
	}
	string[length] = '\0';
	std::cout << string << std::endl;
}

MyString::MyString(const MyString& str) {
	length = str.length;
	string = new char[length + 1];
	for (int i = 0; i < length; i++) {
		string[i] = str.string[i];
	}
	string[length] = '\0';
	std::cout << string << std::endl;
}

MyString& MyString::assign(const MyString& str) {
	if (length < str.length) {
		delete[] string;

		string = new char[str.length + 1];
	}
	for (int i = 0; i < str.length; i++) {
		string[i] = str.string[i];
	}
	length = str.length;
	string[length] = '\0';
	std::cout << string << std::endl;
	return *this;
}
MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);
	if (length < str_length) {
		delete[] string;

		string = new char[str_length + 1];
	}
	for (int i = 0; i < str_length; i++) {
		string[i] = str[i];
	}
	length = str_length; //  �̺κ��� ����
	string[length] = '\0';
	std::cout << string << std::endl;
	return *this;
}
MyString::~MyString() {
	delete[] string;
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
	MyString str1("veryverylongwords");
	MyString str3('c');
	str3.assign(str1);
	str3.assign("test01");
	str3.assign("test0122");
	return 0;
}