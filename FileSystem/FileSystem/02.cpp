#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {

	for (const fs::directory_entry& entry : fs::directory_iterator(fs::current_path() / "a")) {
		std::cout << entry.path() << std::endl;
	}
	/*fs::directory_iterator itr(fs::current_path() / "a");
	while (itr != fs::end(itr)) {
		const fs::directory_entry& entry = *itr;
		std::cout << entry.path() << std::endl;
		itr++;
	}*/
}