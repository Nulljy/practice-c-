#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
	fs::path p("./01.cpp");
	std::cout << "��������: " << fs::current_path() << std::endl;
	std::cout << "�����: " << p.relative_path() << std::endl;
	std::cout << "������: " << fs::absolute(p) << std::endl;
	std::cout << "��������������: " << fs::canonical(p) << std::endl;
}