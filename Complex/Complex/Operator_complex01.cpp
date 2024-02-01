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
	// �ʱ�ȭ�κ�
	bool minus = false;
	if (from > to) return 0;
	if (str[from] == '-') minus = true; // str[from]�� -�� - true, return ���� -1�����ֱ� ����
	if (str[from] == '-' || str[from] == '+') from++; // str[from]�� ��ȣ��� �ε��� ++ �ؼ� ���� ���ڷ� �̵�
	
	double num = 0.0;
	double decimal = 1.0;

	bool integer_part = true;
	// 
	for (int i = from; i <= to; i++) {
		if (isdigit(str[i]) && integer_part) { // ���ڰ�, 
			num *= 10.0; // �Ҽ��� ���̶�� 1, 10, 100 ������ �÷��༭ ���� �����ֱ�
			num += (str[i] - '0'); // num���ٰ� str[i] - '0' �Ѱ��� �����ְ� ����. str[i] - '0' �ϴ� ������ ASCII�ڵ忡�� '1' - '0' �� 49 - 48 = 1�̵��� 
			// str[i]�� '0'�� �ƽ�Ű �ڵ� ���̸� ������ ���ϱ� ����
		}
		else if (str[i] == '.')
			integer_part = false; // �Ҽ��� üũ
		else if (isdigit(str[i]) && !integer_part) { // �ѹ� �Ҽ��� üũ �� �ķδ� ���������� üũ �� ������ ������
			decimal /= 10.0; // �Ҽ����̹Ƿ� 0.1 , 0.01 ������ ���� �о��ֱ� ����
			num += ((str[i] - '0') * decimal); // num���ٰ� ���ϱ� ���ش�, �ƽ�Ű �ڵ� ���̸� ���� decimal�� ���� ����
		}
		else
			break;
	}
	if (minus) num *= -1.0; // minus�� true��� num�� *= -1.0 ����
	return num;
}

Complex Complex::operator+(const Complex& c) {
	Complex temp(real + c.real, img + c.img);
	return temp;
}
Complex Complex::operator+(const char* str) {
	int begin = 0, end = strlen(str); // ���۰� ������ ����
	double str_img = 0.0, str_real = 0.0; // �ʱ�ȭ

	int pos_i = -1; // i�� ���� ���� ���
	for (int i = 0; i != end; i++) {
		if (str[i] == 'i') { // i�� �ִ� �κ� �ķδ� �����
			pos_i = i; // pos_i �������� �Ǽ��δ�
			break;
		}
	}

	// ���� i�� ���ٸ�
	if (pos_i == -1) {
		str_real = get_number(str, begin, end - 1); // str�� ����~ end�� func�� �Ű������� �־��ش�.

		Complex temp(str_real, str_img); // �װ��� �������� temp�� ������ְ� �� ��ü�� �����ְ� ����
		return (*this) + temp;
	}

	str_real = get_number(str, begin, pos_i - 1); // �Ǽ��� num
	str_img = get_number(str, pos_i + 1, end - 1); // ����� num

	if (pos_i >= 1 && str[pos_i - 1] == '-') str_img *= -1.0; // pos_i�� 1���� ũ��, i�� ��ĭ ���� - �ΰ�� ����� -1.0�� �����ش�.
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