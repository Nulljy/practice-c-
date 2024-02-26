#include<iostream>

//���ڵ��� ������ ���ĺ����� ���� ���ڿ�\
// ���� �ƽ�Ű�ڵ忡�� ���ڴ� 48~57, ���ĺ��� 65,97���� ����

struct my_char_traits : public std::char_traits<char> { // char_traits���� �����ϴ� ��� ��� �Լ����� ������ Ŭ���� ����
	static int get_real_rank(char c) {
		if (isdigit(c)) {
			return c + 256;
		}
		return c;
	}

	static bool lt(char c1, char c2)  { // �׿� ���ÿ� ���ϴ� ��Ĵ�� ���۽�Ű�� ���� �������̵� lt, compare �Լ�
		return get_real_rank(c1) < get_real_rank(c2); // c1�� c2���� �۴�
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
	std::basic_string<char, my_char_traits> my_s1 = "1a"; // my_char_traits �����
	std::basic_string<char, my_char_traits> my_s2 = "a1";

	std::cout << "������ �켱������ �� ���� ���ڿ� : " << std::boolalpha
		<< (my_s1 < my_s2) << std::endl; // 1a < a1�� �ǰ� �ؾ��Ѵ�.

	std::string s1 = "1a";
	std::string s2 = "a1";

	std::cout << "�Ϲ� ���ڿ�: " << std::boolalpha << (s1 < s2) << std::endl;

	
	return 0;
}