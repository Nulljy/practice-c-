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
			return false; // find함수는 조건을 찾을 수 없다면 users.end()반환. 
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
	void print() { // users안에 들어간 것은 각기 개별의 객체 인스턴스 이므로 template으로 접근하던 것처럼 불가능
		for (const User& user : users) {
			std::cout << "[" << user.name << ", " << user.level << "] \n";
		}
		std::cout << std::endl;
	}

};

int main() {
	Party party; // users를 가짐
	party.add_user("영희", 19);
	party.add_user("영희", 20);
	party.add_user("영희", 20);
	party.print();
	

	std::cout << std::boolalpha;
	std::cout << "던전 입장 가능?" << party.can_join_dungeon() << std::endl;
	std::cout << "아이템 사용 가능?" << party.can_use_special_item() << std::endl;
	
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
	////std::cout << "3 은 " << std::distance(vec.begin(), result) + 1 << " 번째 원소\n";
	//std::vector<int>::iterator current = vec.begin();
	//while (true) {
	//	current = std::find(current, vec.end(), 3);
	//	if (current == vec.end()) break;
	//	std::cout << "3 은 " << std::distance(vec.begin(), current) + 1 << " 번 째 원소\n";
	//	current++; //findFunc02.cpp
	//}

}