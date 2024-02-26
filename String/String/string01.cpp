#include<iostream>

//숫자들의 순위가 알파벳보다 낮은 문자열\
// 원래 아스키코드에서 숫자는 48~57, 알파벳은 65,97부터 시작

struct my_char_traits : public std::char_traits<char> { // char_traits에서 제공하는 모든 멤버 함수들이 구현된 클래스 전달
	static int get_real_rank(char c) {
		if (isdigit(c)) {
			return c + 256;
		}
		return c;
	}

	static bool lt(char c1, char c2)  { // 그와 동시에 원하는 방식대로 동작시키기 위해 오버라이딩 lt, compare 함수
		return get_real_rank(c1) < get_real_rank(c2); // c1이 c2보다 작다
	}

	static int compare(const char* s1, const char* s2, size_t n) {
		while (n-- != 0) {
			if (get_real_rank(*s1) < get_real_rank(*s2)) {
				return -1;
			}
			if (get_real_rank(*s1) > get_real_rank(*s2)) {
				return 1;
			}
			++s1;
			++s2;
		}
		return 0;
	}
};

int main() {
	std::basic_string<char, my_char_traits> my_s1 = "1a"; // my_char_traits 만들기
	std::basic_string<char, my_char_traits> my_s2 = "a1";

	std::cout << "숫자의 우선순위가 더 낮은 문자열 : " << std::boolalpha
		<< (my_s1 < my_s2) << std::endl; // 1a < a1이 되게 해야한다.

	std::string s1 = "1a";
	std::string s2 = "a1";

	std::cout << "일반 문자열: " << std::boolalpha << (s1 < s2) << std::endl;

	
	return 0;
}