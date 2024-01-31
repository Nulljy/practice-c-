#include <iostream>
#include <string.h>
class MyString {
private:
	char* string_content;
	int string_length;
	int memory_capacity;

public:
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);
	~MyString();

	int length() const;
	int capacity() const;
	int find(int loc, const MyString& str);
	int find(int loc, const char* str);
	int find(int loc, char c);
	int compare(const MyString& str) const;

	char at(int i) const;

	void reserve(int size);

	void print() const;
	void println() const;
	
	MyString& assign(const MyString& str); // = �� ����. 
	MyString& assign(const char* str);

	MyString& insert(int loc, const MyString& str); 
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);

	MyString& erase(int loc, int num);
};

MyString::MyString(char c) {
	string_length = 1;
	memory_capacity = 1;
	string_content = new char[1];
	string_content[0] = c;
}

MyString::MyString(const char* str) {
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) {
		string_content[i] = str[i];
	}
}


MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	memory_capacity = string_length;
	string_content = new char[string_length];
	for (int i = 0; i < string_length; i++) {
		string_content[i] = str.string_content[i];
	}
}

MyString::~MyString() {
	delete[] string_content;
}
char MyString::at(int i) const{
	if (i >= string_length || i < 0) {
		return 0;
	}
	else {
		return string_content[i];
	}
}
int MyString::length() const {
	return string_length;
}

int MyString::capacity() const {
	return memory_capacity;
}

int MyString::find(int loc, const MyString& str) {
	// ã�� �� index loc���� ã�´�, �� ��ü�� string�� str�� string�� �����ϴ��� ã�� ������ �� �ܾ ������ char�� ���� ��
	// ���� ���� ���ٸ� str�� ���̸�ŭ �����ͼ� ++�ϸ鼭 �ƿ� ������ ���� i
	int i, j; // ������ ����
	for ( i = loc; i <= string_length - str.string_length; i++) {
		for ( j = 0; j < str.string_length; j++) {
			if (string_content[i + j] != str.string_content[j]) break;
		}
		if (j == str.string_length) return i;
	}
	return -1;
}
int MyString::find(int loc, const char* str) {
	MyString temp(str);
	return find(loc, temp);
}
int MyString::find(int loc, char c) {
	MyString temp(c);
	return find(loc, temp);
}

int MyString::compare(const MyString& str) const {
	// ���� ��ü�� string�� str�� string ��
	// ���������� �� �ʰԿ��� 1, ������ ���� -1 ��ȯ, 0�� ���� ���ڿ�
	// ���� ���ڿ��ε�, �� ��ü�� ���̰� �� ��ٸ� -1
	for (int i = 0; i < std::min(string_length, str.string_length); i++) {
		if (string_content[i] > str.string_content[i]) {
			return 1;
		}
		else if (string_content[i] < str.string_content[i]) {
			return -1;
		}
	}
	if (string_length == str.string_length) {
		return 0;
	}
	else if (string_length > str.string_length) {
		return 1;
	}
	
	
	return -1;
}

void MyString::reserve(int size) {
	// ���� �޸𸮰� size���� ũ�ٸ� �ƹ��͵� ���ص� �ȴ�.
	if (memory_capacity < size) {
		memory_capacity = size;
		char* prevContent = string_content;
		string_content = new char[size];
		for (int i = 0; i < string_length; i++) {
			string_content[i] = prevContent[i];
		}
		delete[] prevContent;
	}
}

MyString& MyString::assign(const MyString& str) {
	if (str.string_length > memory_capacity) {
		delete[] string_content;
		memory_capacity = str.string_length;
		string_content = new char[string_length];
	}
	for (int i = 0; i < str.string_length; i++) {
		string_content[i] = str.string_content[i];
	}
	string_length = str.string_length;
	return *this;
}
MyString& MyString::assign(const char* str) {
	int strleng = strlen(str);
	if (strleng > memory_capacity) {
		delete string_content;
		memory_capacity = strleng;
		string_content = new char[memory_capacity];
	}
	for (int i = 0; i < strleng; i++) {
		string_content[i] = str[i];
	}
	string_length = strleng;
	return *this;
}

MyString& MyString::insert(int loc, const MyString& str) {
	// loc�� �տ� str�� string_content�� �־��ش�.
	if (loc > string_length || loc < 0) return *this;
	if ((string_length + str.string_length) > memory_capacity) {
		if (memory_capacity * 2 > string_length + str.string_length) {
			memory_capacity *= 2;
		}
		else {
			memory_capacity = string_length + str.string_length;
		}
		// ���� �޸� �����Ҵ��� ���ְ�, ���̵� �������ְ�, ������ �ּҸ� �޸� �������ش�.
		int i;
		char* prevContent = string_content;
		string_content = new char[memory_capacity];
		for (i = 0; i < loc; i++) {
			string_content[i] = prevContent[i]; // loc �������� �Ű��ش�.
		}
		for (int j = 0; j < str.string_length; j++) {
			string_content[i + j] = str.string_content[j];
		}
		for (i; i < string_length; i++) {
			string_content[i + str.string_length] = prevContent[i];
		}
		delete[] prevContent;
		string_length += str.string_length;
		return *this;
	} 
	// ���Ҵ��� �ʿ������, loc �κи� �ڷ� �̷�� insert�� �κ� ä���ֱ�
	for (int i = string_length - 1; i >= loc; i--) {
		string_content[i + str.string_length] = string_content[i];
	}
	for (int j = 0; j < str.string_length; j++) {
		string_content[loc + j] = str.string_content[j];
	}
	string_length += str.string_length;
	return *this;
}
MyString& MyString::insert(int loc, const char* str) {
	MyString temp(str);
	return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) {
	MyString temp(c);
	return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
	// ����� �Լ� loc���� num�� ����
	// loc�κк��� ���� �� ���� ����ŭ ���ܿ��� �ȴ�. �޺κ��� ������ print���� �ȳ���
	// ���� num�� ũ�Ⱑ �ʹ� ũ�ٸ� loc���� �� ���������� �ȴ�.

	if (loc + num > string_length) {
		string_length = loc;
		return *this;
	}
	int i;
	for (i = loc + num; i < string_length; i++) {
		string_content[i - num] = string_content[i];
	}
	string_length -= num;
	return *this;
}

void MyString::print() const{
	std::cout << "length: " << string_length << std::endl;
	std::cout << "memory_capacity: " << memory_capacity << std::endl;
	for (int i = 0; i < string_length; i++) {
		std::cout << string_content[i];
	}
}

void MyString::println() const{
	std::cout << "length: " << string_length << std::endl;
	std::cout << "memory_capacity: " << memory_capacity << std::endl;
	for (int i = 0; i < string_length; i++) {
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}

int main() {
	MyString str1("abcdef");
	MyString str2("abcde");
	std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;
	
	return 0;
}