#include <iostream>
#include <string>
//using namespace std::literals;

int main() {
	/*std::string s1 = "hello"s;
	std::cout << "s1 길이: " << s1.size() << std::endl;*/

	//std::string str = R"(asdfasdf이 안에는 어떤 것들이 와도 // 이런것도 되고 #define hasldf\n\n <-- Escape 안해도 됨)";
	std::string str = R"foo()";)foo";
	std::cout << str;
}