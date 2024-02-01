#include <iostream>
class Complex {
private:
	double real, img;

	double get_number(const char* str, int from, int to);
public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex operator+(const Complex& c);
	Complex operator+(const char* str);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);
	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);
	void println() {
		std::cout << "( " << real << " , " << img << " ) " << std::endl;
	}
};

double Complex::get_number(const char* str, int from, int to) {
	// 초기화부분
	bool minus = false;
	if (from > to) return 0;
	if (str[from] == '-') minus = true; // str[from]이 -면 - true, return 전에 -1곱해주기 위함
	if (str[from] == '-' || str[from] == '+') from++; // str[from]이 부호라면 인덱스 ++ 해서 다음 글자로 이동
	
	double num = 0.0;
	double decimal = 1.0;

	bool integer_part = true;
	// 
	for (int i = from; i <= to; i++) {
		if (isdigit(str[i]) && integer_part) { // 숫자고, 
			num *= 10.0; // 소숫점 앞이라면 1, 10, 100 순으로 늘려줘서 단위 높여주기
			num += (str[i] - '0'); // num에다가 str[i] - '0' 한것을 더해주고 저장. str[i] - '0' 하는 이유는 ASCII코드에서 '1' - '0' 이 49 - 48 = 1이듯이 
			// str[i]와 '0'의 아스키 코드 차이를 정수로 더하기 위함
		}
		else if (str[i] == '.')
			integer_part = false; // 소수점 체크
		else if (isdigit(str[i]) && !integer_part) { // 한번 소수점 체크 된 후로는 정수인지만 체크 후 밑으로 보내줌
			decimal /= 10.0; // 소수점이므로 0.1 , 0.01 순으로 점점 밀어주기 위함
			num += ((str[i] - '0') * decimal); // num에다가 더하기 해준다, 아스키 코드 차이를 위의 decimal과 곱한 수를
		}
		else
			break;
	}
	if (minus) num *= -1.0; // minus가 true라면 num에 *= -1.0 해줌
	return num;
}

Complex Complex::operator+(const Complex& c) {
	Complex temp(real + c.real, img + c.img);
	return temp;
}
Complex Complex::operator+(const char* str) {
	int begin = 0, end = strlen(str); // 시작과 끝나는 길이
	double str_img = 0.0, str_real = 0.0; // 초기화

	int pos_i = -1; // i가 없을 때를 대비
	for (int i = 0; i != end; i++) {
		if (str[i] == 'i') { // i가 있는 부분 후로는 허수부
			pos_i = i; // pos_i 전까지는 실수부다
			break;
		}
	}

	// 만약 i가 없다면
	if (pos_i == -1) {
		str_real = get_number(str, begin, end - 1); // str을 시작~ end를 func에 매개변수로 넣어준다.

		Complex temp(str_real, str_img); // 그것을 바탕으로 temp를 만들어주고 이 객체에 더해주고 리턴
		return (*this) + temp;
	}

	str_real = get_number(str, begin, pos_i - 1); // 실수부 num
	str_img = get_number(str, pos_i + 1, end - 1); // 허수부 num

	if (pos_i >= 1 && str[pos_i - 1] == '-') str_img *= -1.0; // pos_i가 1보다 크고, i의 한칸 전이 - 인경우 허수에 -1.0을 곱해준다.
	Complex temp(str_real, str_img);
	return temp;
}
Complex Complex::operator-(const Complex& c) {
	Complex temp(real - c.real, img - c.img);
	return temp;
}
Complex Complex::operator*(const Complex& c) {
	Complex temp(real * c.real- img * c.img, real * c.img + img * c.real);
 return temp;
 }
 Complex Complex::operator/(const Complex& c) {
 Complex temp(
 (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
 (img * c.real- real * c.img) / (c.real * c.real + c.img * c.img));
 return temp;
 }
 Complex& Complex::operator+=(const Complex& c) {
 (*this) = (*this) + c;
 return *this;
 }
 Complex& Complex::operator-=(const Complex& c) {
 (*this) = (*this)- c;
 return *this;
 }
 Complex& Complex::operator*=(const Complex& c) {
 (*this) = (*this) * c;
 return *this;
 }
 Complex& Complex::operator/=(const Complex& c) {
 (*this) = (*this) / c;
 return *this;
 }
 int main() {
	 Complex a(0, 0);
	 a = a + "-1.1 + i3.923";
	 a.println();
 }