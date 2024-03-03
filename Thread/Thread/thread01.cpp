#include <iostream>
#include <thread>
#include <cstdio>
#include <vector>

using std::thread;
using std::vector;

//void func1() {
//	for (int i = 0; i < 10; i++) {
//		std::cout << "������ 1\n";
//	}
//}
//void func2() {
//	for (int i = 0; i < 10; i++) {
//		std::cout << "������ 2\n";
//	}
//}
//void func3() {
//	for (int i = 0; i < 10; i++) {
//		std::cout << "������ 3\n";
//	}
//}

void worker(vector<int>::iterator start, vector<int>::iterator end, int* result) {
	int sum = 0;
	for (auto itr = start; itr < end; ++itr) {
		sum += *itr;
	}
	*result = sum;

	thread::id this_id = std::this_thread::get_id(); // thread�� id�� ��� ���
	printf("������ %x���� %d���� %d���� ����� ��� : %d \n", this_id, *start, *(end - 1), sum);
}

int main() {
	vector<int> data(10000); // int vector �ʱ�ȭ
	for (int i = 0; i < 10000; i++) {
		data[i] = i;
	}

	vector<int> partial_sums(4); // int vector �ʱ�ȭ

	vector<thread> workers; // thread vector ����

	for (int i = 0; i < 4; i++) {
		// thread�� �Ҷ� bind�� �����ϸ� �ȴ�.
		// worker�� �Լ��̴�.
		workers.push_back(
			thread(
				worker, data.begin() + i * 2500, data.begin() + (i + 1) * 2500, &partial_sums[i]
			) // thread�� �����ڴ� ù��° ���ڰ� �Լ��� �Լ� ��ü, ���� arg...�� �� �Լ��� �� �Ű����ڰ� �ȴ�.
		);
	}

	for (int i = 0; i < 4; i++) {
		workers[i].join();
	}

	int total = 0;
	for (int i = 0; i < 4; i++) {
		total += partial_sums[i];
	}
	std::cout << "��ü ��: " << total << std::endl;

	//thread t1(func1);
	//thread t2(func2);
	//thread t3(func3);

	///*t1.join();
	//t2.join();
	//t3.join();*/
	//t1.detach(); // �����带 �����ϰ� �ؾ�����°�
	//t2.detach();
	//t3.detach();

	//std::cout << "���� �Լ� ����\n";
}