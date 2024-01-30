#include <iostream>

/*
	std::cout
	std::endl
	1. memory capacity 만들기 V
	2. 레퍼런스를 리턴하는 insert 구현
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
	length = str_length; //  이부분이 문제
	string[length] = '\0';
	std::cout << string << std::endl;
	return *this;
}

MyString& MyString::insert(int index, const MyString& str) {
	// 인덱스부터 뒤의 레퍼런스의 단어를 넣어주기
	// 메모리 capacity가 남아있나?
	// 기존의 글을 저장해서 옮겨 준 후 string에 넣어주고 그 후로 넣어주어야한다.

	if (str.length + length > memory_capacity) {
		// 재할당
		memory_capacity = str.length + length;
		char* prevString = string;
		string = new char[memory_capacity + 1];
		for (int i = 0; i < length; i++) {
			string[i] = prevString[i];
		}
		delete[] prevString; // 메모리 해제
	}
	length += str.length;
	for (int i = 0; i < str.length; i++) { // '\0'부터 넣어주어야함
		string[index + i] = str.string[i]; // string[string의 길이가 끝난 시점] = str.string[0]부터 끝까지
	}
	string[length] = '\0';
	return *this;
}
MyString& MyString::insert(int index, const char* str) {
	// str의 길이 얻기
	int str_length = strlen(str);
	// length + str의 length가 memorycapacity를 넘는지 확인 
	if (length + str_length > memory_capacity) {
		// 재할당
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
	for (int i = 0; i < str_length; i++) { // 기존 글자 뒤의 글자 복사
		string[index + i] = str[i];
	}
	string[length] = '\0'; // 지금 궁금한게, 기존의 string의 끝까지 쓴 후 복사가 아닌 중간에 짤라서 글자를 넣게되면 memorycapacity는..?
	// memcapa = str.length + (index - length) 만약 hi의 i 에서부터 들어가면 3 + (2 - 1) 
	return *this;
}

void MyString::assignFunC(int str_length, char* string) { // *& 레퍼런스를 변수로 넣어서 지역변수에서 실행한 변경 사항이 저장되도록 함 
	memory_capacity = length + str_length;
	char* prevString = string;
	string = new char[memory_capacity + 1];
	for (int i = 0; i < length; i++) {
		string[i] = prevString[i];
	}
	delete[] prevString;
}
//void MyString::assignFunC(int str_length, char*& string) { // *& 레퍼런스를 변수로 넣어서 지역변수에서 실행한 변경 사항이 저장되도록 함 
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