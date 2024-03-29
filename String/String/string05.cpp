#include <iostream>
#include <string>

int main() {
	std::u16string u16_str = u"안녕하세용 모두에 코드에 오신 것을 환영합니다";

	std::string jaum[] = { "ㄱ", "ㄲ", "ㄴ", "ㄷ", "ㄸ", "ㄹ", "ㅁ",
						   "ㅂ", "ㅃ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅉ",
						   "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ" };

	for (char16_t c : u16_str) {
		// 한글 유니코드가 아니면 continue;
		if (!(0xAC00 <= c && c <= 0xD7A3)) {
			continue;
		}
		int offset = c - 0xAC00; // 변위차 0xAC00이 음절 '가'에 해당, 따라서 c가 0xAC00과 얼마나 차이가 나냐
		int jaum_offset = offset / 0x24C; // 초성엔 0x24C 만큼 존재
		std::cout << jaum[jaum_offset];
	}
	
	return 0;
}