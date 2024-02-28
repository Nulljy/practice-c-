#include <iostream>
#include<string>
#include <string_view>

void* operator new(std::size_t count) {
	std::cout << count << " bytes 할당 " << std::endl;
	return malloc(count);
}

bool contains_very(std::string_view std) {
	return std.find("very") != std::string_view::npos;
}

int main() {
	// std::string 객체 불필요하게 생성
	std::cout << std::boolalpha << contains_very("c++ string is very easy to use") << std::endl;
	std::cout << std::boolalpha << contains_very("c++ string is not easy to use") << std::endl;

	std::cout << " ------------------------------ " << std::endl;
	std::string str = "some long long long long long string";
	std::cout << contains_very(str) << std::endl;
	return 0;
}