#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
	fs::path p("./01.cpp");
	std::cout << "내현재경로: " << fs::current_path() << std::endl;
	std::cout << "상대경로: " << p.relative_path() << std::endl;
	std::cout << "절대경로: " << fs::absolute(p) << std::endl;
	std::cout << "공식적인절대경로: " << fs::canonical(p) << std::endl;
}