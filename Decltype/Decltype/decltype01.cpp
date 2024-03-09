#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
template<typename T>
class A {
public:
	int f() const{
		return 42;
	}
};

template<typename T>
decltype(T().f()) call_f_and_return(T& a) {
	return a.f();
}

int main() {
	A<int> a;
	int tmp = call_f_and_return(a);
	cout << tmp << endl;
}