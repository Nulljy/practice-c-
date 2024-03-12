#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;
int main() {
	fs::path p("./a");
	while (true) {
		bool is_modified = false;
		for (const auto& entry : fs::directory_iterator("./a")) {
			const std::string ext = entry.path().extension().string();
			if (ext == ".txt") {
				fs::remove(entry.path());
				is_modified = true;
				break;
			}
		}
		if (!is_modified) {
			break;
		}
	}
}