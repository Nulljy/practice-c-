#include <iostream>
#include <memory>
#include <vector>

// ����Ʈ ������
class A {
	int* data;
	std::shared_ptr<A> other;

public:
	A() {
		data = new int[100];
		std::cout << "�ڿ� ����\n";
	}

	A(int a) {
		std::cout << "�ڿ� ����\n";
		data = new int[100];
		data[0] = a;
	};
	A(const A& a) = delete;

	void some() { std::cout << "�� : " << data[0] << std::endl; }
	//void some() { std::cout << "�Ϲ� �����Ϳ� �����ϰ� ��밡��!\n"; }

	void do_sth(int a) {
		std::cout << "���𰡸� �Ѵ�!" << std::endl;
		data[0] = a;
	}

	void set_other(std::shared_ptr<A> o) { other = o; }

	~A() {
		std::cout << "�ڿ� �Ҹ�\n";
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
//	//pb�� ����
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
	//std::unique_ptr<A> pa(new A(1)); // ��������� pa�� vector������ �̵� �����־�� �Ѵ�.
	//vec.push_back(std::move(pa)); // ������ unique_ptr�� ���縦 ������� �ʱ� ����
	/*std::vector<std::unique_ptr<A>> vec;
	vec.emplace_back(new A(1));
	vec.back()->some();*/

	//std::vector<std::shared_ptr<A>> vec;
	//std::shared_ptr<A> a(new A());
	//vec.push_back(a);
	//vec.push_back(std::shared_ptr<A>(vec[0]));
	//vec.push_back(std::shared_ptr<A>(vec[1]));

	//// ù ���� �Ҹ�
	//std::cout << "ù ��° �Ҹ�" << std::endl;
	//vec.erase(vec.begin());
	//std::cout << a.use_count() << std::endl;
	//std::cout << "�� ��° �Ҹ�" << std::endl;
	//vec.erase(vec.begin());
	//std::cout << a.use_count() << std::endl;
	//std::cout << "������ �Ҹ�" << std::endl;
	//vec.erase(vec.begin());
	//std::cout << a.use_count() << std::endl;
	std::shared_ptr<A> pa = std::make_shared<A>();
	std::shared_ptr<A> pb = std::make_shared<A>();

	pa->set_other(pb);
	pb->set_other(pa);
}
