#include <iostream>


int fibonacci(int a) {
	if (a <= 1) {
		return 1;
	}
	else {
		return fibonacci(a - 1) + fibonacci(a - 2);
	}
}

int main() {
	int a = 10;
	std::cout << fibonacci(a);
	//int bef = 1, cur = 1;

	//for (int i = 2; i <= 10; i++) { 
	//	// 피보나치수열 10, 2부터 시작하는 이유는 cur = cur + bef때문에
	//	// fibonacci(3)일 때 1 + 2가 되어야하기 때문 
	//	int temp = cur;
	//	cur = cur + bef;
	//	bef = temp;
	//}

	/*std::cout << cur << std::endl;*/
}