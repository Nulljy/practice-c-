#include <iostream>
#include <string>

void* operator new(std::size_t count) {
	std::cout << count << " bytes 且寸 " << std::endl;
	return malloc(count);
}

int main() {
	std::cout << "s1 积己---\n";
	std::string s1 = "this is a pretty long sentence!!";
	std::cout << "s1 农扁: " << sizeof(s1) << std::endl; // 40
	
	std::cout << "s2 积己---\n";
	std::string s2 = "short sentence";
	std::cout << "s2 农扁: " << sizeof(s2) << std::endl; // 40

	return 0;
}