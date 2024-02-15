#include <fstream>
#include <iostream>
#include <string>

int main() {
	// 파일 읽기 준비
	std::ifstream in("test.txt");
	char buf[100];

	if (!in.is_open()) {
		std::cout << "해당 txt가 존재하지 않습니다.\n";
		return 0;
	}
	while (in) {
		in.getline(buf, 100); // '\n'을 마주치면 거기까지 buf에 저장
		std::cout << buf << std::endl;
	}
	
	return 0;
}