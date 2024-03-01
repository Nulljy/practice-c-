#include <iostream>
#include <memory>
#include <vector>

// 스마트 포인터
class A {
	int* data;
	std::shared_ptr<A> other;

public:
	A() {
		data = new int[100];
		std::cout << "자원 생성\n";
	}

	A(int a) {
		std::cout << "자원 생성\n";
		data = new int[100];
		data[0] = a;
	};
	A(const A& a) = delete;

	void some() { std::cout << "값 : " << data[0] << std::endl; }
	//void some() { std::cout << "일반 포인터와 동일하게 사용가능!\n"; }

	void do_sth(int a) {
		std::cout << "무언가를 한다!" << std::endl;
		data[0] = a;
	}

	void set_other(std::shared_ptr<A> o) { other = o; }

	~A() {
		std::cout << "자원 소멸\n";
		delete[] data;
	}
};

void thrower() {
	throw 1;
}

//void do_something() { 
//	std::unique_ptr<A> pa(new A());
//	std::cout << "pa : ";
//	pa->some();
//
//	//pb에 이전
//	std::unique_ptr<A> pb = std::move(pa);
//	std::cout << "pb : ";
//	pb->some();
//
//
//
//	/*A* pa = new A();
//	thrower();
//	delete pa;*/
//}

void do_something(std::unique_ptr<A>& ptr) { ptr->do_sth(3); }
void do_something(A* ptr) { ptr->do_sth(3); }

int main() {
	/*std::unique_ptr<A> pa(new A());
	do_something(pa.get());*/
	//std::unique_ptr<A> pa(new A(1)); // 명시적으로 pa를 vector안으로 이동 시켜주어야 한다.
	//vec.push_back(std::move(pa)); // 원인은 unique_ptr이 복사를 허용하지 않기 때문
	/*std::vector<std::unique_ptr<A>> vec;
	vec.emplace_back(new A(1));
	vec.back()->some();*/

	//std::vector<std::shared_ptr<A>> vec;
	//std::shared_ptr<A> a(new A());
	//vec.push_back(a);
	//vec.push_back(std::shared_ptr<A>(vec[0]));
	//vec.push_back(std::shared_ptr<A>(vec[1]));

	//// 첫 원소 소멸
	//std::cout << "첫 번째 소멸" << std::endl;
	//vec.erase(vec.begin());
	//std::cout << a.use_count() << std::endl;
	//std::cout << "두 번째 소멸" << std::endl;
	//vec.erase(vec.begin());
	//std::cout << a.use_count() << std::endl;
	//std::cout << "마지막 소멸" << std::endl;
	//vec.erase(vec.begin());
	//std::cout << a.use_count() << std::endl;
	std::shared_ptr<A> pa = std::make_shared<A>();
	std::shared_ptr<A> pb = std::make_shared<A>();

	pa->set_other(pb);
	pb->set_other(pa);
}
