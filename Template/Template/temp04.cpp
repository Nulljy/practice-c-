#include <iostream>

template<int X, int Y> // �Լ��� ġ�� �Ű����� �� ������
struct GCD { // �Լ� �̸�ó�� ����
	static const int value = GCD<Y, X% Y>::value; // ����Լ��� ����
};

template<int X>
struct GCD<X, 0> { // ��� �� ����
	static const int value = X; // ��� ������ ���ϰ����� �����ϸ� �ɵ�
};


int main() {
	const int a = 15;
	const int b = 12; // 12, 3 = 0 ���� 3
	std::cout << a << "�� " << b << "�� �ִ� ������� " << GCD<a, b>::value;

	return 0;
}