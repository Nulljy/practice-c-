#include <iostream>

/*
	std::cout
	std::endl
	1. 문자(char) 로 부터의 문자열 생성, C 문자열 (char *) 로 부터의 생성
	2. 문자열 길이를 구하는 함수
	3. 문자열 뒤에 다른 문자열 붙이기
	4. 문자열 내에 포함되어 있는 문자열 구하기
	5. 문자열이 같은지 비교
	6. 문자열 크기 비교 (사전 순)
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