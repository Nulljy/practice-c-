#include <fstream>
#include <iostream>
#include <string>

int main() {
	// 파일 읽기 준비
	std::ifstream in("test.txt", std::ios::binary);
	std::string s = "";

	if (in.is_open()) {
		//위치 지정자를 파일 끝으로 옮긴다.
		in.seekg(0, std::ios::end);

		// 그 위치를 읽는다.
		int size = in.tellg();

		// 그 크기의 문자열을 할당
		s.resize(size);

		// 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
		in.seekg(0, std::ios::beg);

		// 파일 전체 내용을 읽어서 문자열에 저장
		in.read(&s[0], size);
		std::cout << s << std::endl;
	}
	else {
		std::cout << "파일을 찾을 수 없습니다.\n";
	}
	return 0;
}