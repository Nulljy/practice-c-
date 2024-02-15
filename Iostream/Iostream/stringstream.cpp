#include <iostream>
#include <sstream>

int main() {
	std::istringstream ss("123"); // istringstream은 마치 문자열을 하나의 스트림이라 생각하게 해주는 가상화 장치
	int x;
	ss >> x;

	std::cout << "입력 받은 데이터 :: " << x << std::endl;

	return 0;
}
