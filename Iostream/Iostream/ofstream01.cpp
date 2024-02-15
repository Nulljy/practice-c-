#include <iostream>
#include <fstream>
#include <string>

int main() {
	// 파일 쓰기
	std::ofstream out("test.txt", std::ios::app);

	std::string s;
	if (out.is_open()) {
		out << "보너스";
	}

	return 0;
}