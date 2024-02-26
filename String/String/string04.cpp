#include <iostream>
#include <string>
int main() {

	std::string str = u8"이건UTF-8 문자열입니다";
	size_t i = 0;
	size_t len = 0;
	while (i < str.size()) {
		int char_size = 0;
		if ((str[i] & 0b11111000) == 0b11110000) {
			char_size = 4;
		}
		else if ((str[i] & 0b11110000) == 0b11100000) {
			char_size = 3;
		}
		else if ((str[i] & 0b11100000) == 0b11000000) {
			char_size = 2;
		}
		else if ((str[i] & 0b10000000) == 0b00000000) { // 2진법 변환 후 & 연산 하는 것
			char_size = 1;
		}
		else {
			std::cout << "이상한문자발견!" << std::endl;
			char_size = 1;
		}
		std::cout << str.substr(i, char_size) << std::endl;
		i += char_size;
		len++;
	}
	std::cout << "문자열의실제길이: " << len << std::endl;
}