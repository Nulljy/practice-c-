#include <iostream>
#include <string>

using namespace std;
int main() {
	int t;
	while (true) {
		std::cin >> t;
		if (std::cin.fail()) { // fail함수
			std::cout << "제대로 입력해주세요" << std::endl;
			std::cin.clear(); // 플래그 초기화 함수
			std::cin.ignore(100, '\n'); // ignore함수
		}
		if (t == 0) break;
		std::cout << "입력 :: " << t << std::endl;
	}
	
	//while (std::cin >> t) {
	//	std::cout << "입력 : " << t << std::endl; // 'c'입력시 failbit이 on되어서 버퍼의 'c\n'은 손대지 않고 리턴해버린다.
	//	if (t == 0) break; // 이유는 t가 int 타입인데 'c'는 char 형태라서
	//}
	return 0;
}