#include <iostream>
#include <string>

using std::string;
class Vector {
	string* data;
	int capacity;
	int length;

public:
	// ������
	Vector(int n = 1); // �̰� ���� �ǹ�? ����Ʈ ������. ex) Vector::Vector(int n) : data(new string[n]) ... {}

	void push_back(string s);

	string operator[](int i);

	void remove(int x);

	int size();

	~Vector();
};

void Vector::push_back(string s) {
	if (capacity <= length) {
		string* temp = new string[capacity * 2];
		// ������ data �Ű��ֱ�
		for (int i = 0; i < length; i++) {
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
		capacity *= 2;
	}

	data[length] = s;
	length++;
}

string Vector::operator[](int i) {
	return data[i];
}

void Vector::remove(int x) {
	// index x�� �ִ� ���� ����� �� => x+1�� x�� �ִ°�
	for (int i = x + 1; i < length; i++) { // ���� length���� x + 1�� ũ�ٸ�? �����غ���
		data[i - 1] = data[i];
	}
	length--;
}

int Vector::size() {
	return length;
}

Vector::~Vector() {
	delete[] data;
}


int main() {

	return 0;
}