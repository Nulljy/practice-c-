#include <iostream>
#include <string>

void* operator new(std::size_t count) {
	std::cout << count << " bytes �Ҵ� " << std::endl;
	return malloc(count);
}

int main() {
	std::cout << "s1 ����---\n";
	std::string s1 = "this is a pretty long sentence!!";
	std::cout << "s1 ũ��: " << sizeof(s1) << std::endl; // 40
	
	std::cout << "s2 ����---\n";
	std::string s2 = "short sentence";
	std::cout << "s2 ũ��: " << sizeof(s2) << std::endl; // 40

	return 0;
}