#include <iostream>
#include <thread>
#include <cstdio>
#include <vector>

using std::thread;
using std::vector;

//void func1() {
//	for (int i = 0; i < 10; i++) {
//		std::cout << "스레드 1\n";
//	}
//}
//void func2() {
//	for (int i = 0; i < 10; i++) {
//		std::cout << "스레드 2\n";
//	}
//}
//void func3() {
//	for (int i = 0; i < 10; i++) {
//		std::cout << "스레드 3\n";
//	}
//}

void worker(vector<int>::iterator start, vector<int>::iterator end, int* result) {
	int sum = 0;
	for (auto itr = start; itr < end; ++itr) {
		sum += *itr;
	}
	*result = sum;

	thread::id this_id = std::this_thread::get_id(); // thread의 id를 얻는 방법
	printf("스레드 %x에서 %d부터 %d까지 계산한 결과 : %d \n", this_id, *start, *(end - 1), sum);
}

int main() {
	vector<int> data(10000); // int vector 초기화
	for (int i = 0; i < 10000; i++) {
		data[i] = i;
	}

	vector<int> partial_sums(4); // int vector 초기화

	vector<thread> workers; // thread vector 선언

	for (int i = 0; i < 4; i++) {
		// thread를 할때 bind를 생각하면 된다.
		// worker는 함수이다.
		workers.push_back(
			thread(
				worker, data.begin() + i * 2500, data.begin() + (i + 1) * 2500, &partial_sums[i]
			) // thread의 생성자는 첫번째 인자가 함수나 함수 객체, 다음 arg...는 그 함수에 들어갈 매개인자가 된다.
		);
	}

	for (int i = 0; i < 4; i++) {
		workers[i].join();
	}

	int total = 0;
	for (int i = 0; i < 4; i++) {
		total += partial_sums[i];
	}
	std::cout << "전체 합: " << total << std::endl;

	//thread t1(func1);
	//thread t2(func2);
	//thread t3(func3);

	///*t1.join();
	//t2.join();
	//t3.join();*/
	//t1.detach(); // 쓰레드를 실행하고 잊어버리는것
	//t2.detach();
	//t3.detach();

	//std::cout << "메인 함수 종료\n";
}