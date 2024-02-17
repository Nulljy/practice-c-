#include <iostream>
#include <string>

using std::string;
class Vector {
	string* data;
	int capacity;
	int length;

public:
	// 생성자
	Vector(int n = 1); // 이게 무슨 의미? 디폴트 생성자. ex) Vector::Vector(int n) : data(new string[n]) ... {}

	void push_back(string s);

	string operator[](int i);

	void remove(int x);

	int size();

	~Vector();
};

void Vector::push_back(string s) {
	if (capacity <= length) {
		string* temp = new string[capacity * 2];
		// 기존의 data 옮겨주기
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
	// index x에 있는 것을 지우는 것 => x+1을 x에 넣는것
	for (int i = x + 1; i < length; i++) { // 만약 length보다 x + 1이 크다면? 실험해보기
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