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
	//	// �Ǻ���ġ���� 10, 2���� �����ϴ� ������ cur = cur + bef������
	//	// fibonacci(3)�� �� 1 + 2�� �Ǿ���ϱ� ���� 
	//	int temp = cur;
	//	cur = cur + bef;
	//	bef = temp;
	//}

	/*std::cout << cur << std::endl;*/
}