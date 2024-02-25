#include <iostream>
#include <functional>
#include <iostream>
#include <string>
#include<algorithm>
#include <vector>

//template <typename Iter>
//void print(Iter begin, Iter end) {
//	while (begin != end) {
//		std::cout << "[" << *begin << "] ";
//		begin++;
//	}
//	std::cout << std::endl;
//}

struct User {
	std::string name;
	int level;

	User(std::string name, int level) : name(name), level(level) {}
	bool operator==(const User& user) const {
		if (name == user.name && level == user.level) return true;
		return false;
	}
};

class Party {

public:
	std::vector<User> users;
	bool add_user(std::string name, int level) {
		User new_user(name, level);
		if (std::find(users.begin(), users.end(), new_user) != users.end()) {
			return false; // find�Լ��� ������ ã�� �� ���ٸ� users.end()��ȯ. 
		}
		users.push_back(new_user);
		return true;
	}

	bool can_join_dungeon() {
		return std::all_of(users.begin(), users.end(),
			[](User& user) { return user.level >= 15; });
	}

	bool can_use_special_item() {
		return std::any_of(users.begin(), users.end(),
			[](User& user) {return user.level >= 19; });
	}
	void print() { // users�ȿ� �� ���� ���� ������ ��ü �ν��Ͻ� �̹Ƿ� template���� �����ϴ� ��ó�� �Ұ���
		for (const User& user : users) {
			std::cout << "[" << user.name << ", " << user.level << "] \n";
		}
		std::cout << std::endl;
	}

};

int main() {
	Party party; // users�� ����
	party.add_user("����", 19);
	party.add_user("����", 20);
	party.add_user("����", 20);
	party.print();
	

	std::cout << std::boolalpha;
	std::cout << "���� ���� ����?" << party.can_join_dungeon() << std::endl;
	std::cout << "������ ��� ����?" << party.can_use_special_item() << std::endl;
	
	return 0;

	//std::vector<int> vec;
	//vec.push_back(5);
	//vec.push_back(3);
	//vec.push_back(1);
	//vec.push_back(2);
	//vec.push_back(3);
	//vec.push_back(4);
	//vec.push_back(3);

	////std::vector<int>::iterator result = std::find(vec.begin(), vec.end(), 3); // findFunc01.cpp
	////std::cout << "3 �� " << std::distance(vec.begin(), result) + 1 << " ��° ����\n";
	//std::vector<int>::iterator current = vec.begin();
	//while (true) {
	//	current = std::find(current, vec.end(), 3);
	//	if (current == vec.end()) break;
	//	std::cout << "3 �� " << std::distance(vec.begin(), current) + 1 << " �� ° ����\n";
	//	current++; //findFunc02.cpp
	//}

}