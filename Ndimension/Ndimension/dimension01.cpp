#include <iostream>



class Array {
	const int dim;
	int* size;

	struct Address 
	{
		int level;
		void* next;
	};
	Address* top;

	void initialize_address(Address* current) {
		if (!current) return;
		if (current->level == dim - 1) { // 이 주소 포인터가 자료객체를 가리키는 포인터면
			current->next = new int[size[current->level]];
			return;
		}
		current->next = new Address[size[current->level]]; 
		for (int i = 0; i != size[current->level]; i++) { // 레벨 1에서 두번 
			(static_cast<Address*>(current->next) + i)->level = current->level + 1; // 2차원
			initialize_address(static_cast<Address*>(current->next) + i);
		}

	}
	
	void delete_address(Address* current) {
		if (!current) return;
		for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) { // dim -1보다 같거나 크면 못들어감
			// 다음 레벨에서 delete_address 실행 next + i
			delete_address((static_cast<Address*>(current->next) + i));
		}
		delete[] current->next;
	}

public:
	Array(int dim, int* array_size) : dim(dim) { // 2, {1, 2}
		size = new int[dim];
		for (int i = 0; i < dim; i++) {
			size[i] = array_size[i]; // size[0] = array_size[0] = 1 //// 2
		}
		top = new Address;
		top->level = 0;
		initialize_address(top);
	}

	Array(const Array& arr) : dim(arr.dim) {
		size = new int[dim];
		for (int i = 0; i < dim; i++) size[i] = arr.size[i];
		top = new Address;
		top->level = 0;
		initialize_address(top);
	}

	~Array() {
		delete_address(top);
		delete[] size;
	}
};

int main() {
	int in1[2] = {2, 3};
	Array arr(2, in1);
	return 0;
}