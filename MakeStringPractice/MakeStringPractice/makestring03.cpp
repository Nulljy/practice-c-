#include <iostream>

/*
	std::cout
	std::endl
	1. memory capacity ����� V
	2. ���۷����� �����ϴ� insert ����
*/
int getLength(char* text);

class MyString {
private:
	char* string;
	int length;
	int memory_capacity;

public:
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);
	MyString& insert(int index, const MyString& str);
	MyString& insert(int index, const char* str);
	~MyString();
	void assignFunC(int str_length, char* string);
	int getLength();
	void print();
	void println();

};

MyString::MyString(char c) {
	string = new char[2];
	string[0] = c;
	string[1] = '\0';
	length = 1;
	memory_capacity = 2;
	std::cout << string << std::endl;
}

MyString::MyString(const char* str) {
	length = strlen(str);
	string = new char[length + 1];
	memory_capacity = length;
	for (int i = 0; i < length; i++) {
		string[i] = str[i];
	}
	string[length] = '\0';
	std::cout << string << std::endl;
}

MyString::MyString(const MyString& str) {
	length = str.length;
	string = new char[length + 1];
	memory_capacity = length;
	for (int i = 0; i < length; i++) {
		string[i] = str.string[i];
	}
	string[length] = '\0';
	std::cout << string << std::endl;
}

void MyString::print() {
	std::cout << "length of this object: " << length << std::endl;
	std::cout << "memory_capacity of this object: " << memory_capacity << std::endl;
	std::cout << string << std::endl;
}

int MyString::getLength() {
	return length;
}

MyString& MyString::assign(const MyString& str) {
	if (memory_capacity < str.length) {
		delete[] string;
		memory_capacity = str.length;
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
	if (memory_capacity < str_length) {
		delete[] string;
		memory_capacity = str_length;
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

MyString& MyString::insert(int index, const MyString& str) {
	// �ε������� ���� ���۷����� �ܾ �־��ֱ�
	// �޸� capacity�� �����ֳ�?
	// ������ ���� �����ؼ� �Ű� �� �� string�� �־��ְ� �� �ķ� �־��־���Ѵ�.

	if (str.length + length > memory_capacity) {
		// ���Ҵ�
		memory_capacity = str.length + length;
		char* prevString = string;
		string = new char[memory_capacity + 1];
		for (int i = 0; i < length; i++) {
			string[i] = prevString[i];
		}
		delete[] prevString; // �޸� ����
	}
	length += str.length;
	for (int i = 0; i < str.length; i++) { // '\0'���� �־��־����
		string[index + i] = str.string[i]; // string[string�� ���̰� ���� ����] = str.string[0]���� ������
	}
	string[length] = '\0';
	return *this;
}
MyString& MyString::insert(int index, const char* str) {
	// str�� ���� ���
	int str_length = strlen(str);
	// length + str�� length�� memorycapacity�� �Ѵ��� Ȯ�� 
	if (length + str_length > memory_capacity) {
		// ���Ҵ�
		assignFunC(str_length, string);
		/*memory_capacity = length + str_length;
		char* prevString = string;
		string = new char[memory_capacity + 1];
		for (int i = 0; i < length; i++) {
			string[i] = prevString[i];
		}
		delete[] prevString;*/
	}
	length += str_length;
	for (int i = 0; i < str_length; i++) { // ���� ���� ���� ���� ����
		string[index + i] = str[i];
	}
	string[length] = '\0'; // ���� �ñ��Ѱ�, ������ string�� ������ �� �� ���簡 �ƴ� �߰��� ©�� ���ڸ� �ְԵǸ� memorycapacity��..?
	// memcapa = str.length + (index - length) ���� hi�� i �������� ���� 3 + (2 - 1) 
	return *this;
}

void MyString::assignFunC(int str_length, char* string) { // *& ���۷����� ������ �־ ������������ ������ ���� ������ ����ǵ��� �� 
	memory_capacity = length + str_length;
	char* prevString = string;
	string = new char[memory_capacity + 1];
	for (int i = 0; i < length; i++) {
		string[i] = prevString[i];
	}
	delete[] prevString;
}
//void MyString::assignFunC(int str_length, char*& string) { // *& ���۷����� ������ �־ ������������ ������ ���� ������ ����ǵ��� �� 
//	memory_capacity = length + str_length;
//	char* prevString = string;
//	string = new char[memory_capacity + 1];
//	for (int i = 0; i < length; i++) {
//		string[i] = prevString[i];
//	}
//	delete[] prevString;
//}

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
	MyString str1("Hi");
	//MyString str3("bye");
	str1.insert(2, "bye");
	str1.print();
	return 0;
}