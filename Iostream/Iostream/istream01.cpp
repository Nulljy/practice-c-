#include <iostream>
#include <string>

using namespace std;
int main() {
	int t;
	std::cin >> t;
	std::cout << "fail 비트가 켜진 상태이므로, 입력x\n";
	std::string s;
	std::cin >> s;
	//while (std::cin >> t) {
	//	std::cout << "입력 : " << t << std::endl; // 'c'입력시 failbit이 on되어서 버퍼의 'c\n'은 손대지 않고 리턴해버린다.
	//	if (t == 0) break; // 이유는 t가 int 타입인데 'c'는 char 형태라서
	//}
	return 0;
}