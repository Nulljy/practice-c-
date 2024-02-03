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
		for (int i = 0; i != size[current->level]; i++) {
			(static_cast<Address*>(current->next) + i)->level = current->level + 1;
			initialize_address(static_cast<Address*>(current->next) + i);
		}
	}

public:
	Array(int dim, int* array_size) : dim(dim) { // 2, {1, 2}
		size = new int[dim];
		for (int i = 0; i < dim; i++) {
			size[i] = array_size[i]; // size[0] = array_size[0] = 1 //// 2
		}
	}
};

int main() {

	return 0;
}