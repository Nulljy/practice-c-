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
	void reserve(int size);

	char at(int i) const;

	void print() const;
	void println() const;
	
	MyString& assign(const MyString& str); // = 과 같다. 
	MyString& assign(const char* str);

	MyString& insert(int loc, const MyString& str); 
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);
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

void MyString::reserve(int size) {
	// 현재 메모리가 size보다 크다면 아무것도 안해도 된다.
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
	// loc의 앞에 str의 string_content를 넣어준다.
	if (loc > string_length || loc < 0) return *this;
	if ((string_length + str.string_length) > memory_capacity) {
		if (memory_capacity * 2 > string_length + str.string_length) {
			memory_capacity *= 2;
		}
		else {
			memory_capacity = string_length + str.string_length;
		}
		// 새로 메모리 동적할당을 해주고, 길이도 조정해주고, 기존의 주소를 메모리 해제해준다.
		int i;
		char* prevContent = string_content;
		string_content = new char[memory_capacity];
		for (i = 0; i < loc; i++) {
			string_content[i] = prevContent[i]; // loc 전까지를 옮겨준다.
		}
		for (int j = 0; j < str.string_length; j++) {
			string_content[i + j] = str.string_content[j];
		}
		for (; i < string_length; i++) {
			string_content[i + str.string_length] = prevContent[i];
		}
		delete[] prevContent;
		string_length += str.string_length;
		return *this;
	} 
	return *this;
}
MyString& MyString::insert(int loc, const char* str) {

	return *this;
}
MyString& MyString::insert(int loc, char c) {

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
	MyString str1("abcdefghijklnm");
	str1.println();
	str1.assign("dragon");
	str1.println();
	return 0;
}