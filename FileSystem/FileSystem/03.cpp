#include <filesystem>
#include <iostream>
#include <fstream>

namespace fs = std::filesystem;

int main() {
	fs::path p("./c/d/e/f");
	std::cout << "Does " << p << " exist? [" << std::boolalpha << fs::exists(p)
		<< "]" << std::endl;
	fs::create_directories(p);
	std::cout << "Does " << p << " exist? [" << fs::exists(p) << "]" << std::endl;
	std::cout << "Is " << p << " directory? [" << fs::is_directory(p) << "]"
		<< std::endl;
}