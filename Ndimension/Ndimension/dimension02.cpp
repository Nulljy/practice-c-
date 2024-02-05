#include <iostream>

namespace MyArray {
	class Array;
	class Int;

	class Array {
		friend Int;
		const int dim;
		int* size;

		struct Address {
			int level;
			void* next;
		};
		Address* top;

		public:
		Array(int dim, int* array_size) : dim(dim) {
			size = new int[dim];
			for (int i = 0; i < dim; i++) {
				size[i] = array_size[i];
			}
			top = new Address;
			top->level = 0;

			// �Լ�
			initialize_address(top);
		}
		Array(const Array& arr) : dim(arr.dim) {
			size = new int[dim];
			for (int i = 0; i < dim; i++) {
				size[i] = arr.size[i];
			}
			top = new Address;
			top->level = 0;

			// �Լ�
			initialize_address(top);
		}
		// {4, 3, 1}
		void initialize_address(Address* current) { // �ּ� �ʱ�ȭ
			if (!current) return;
			// ��ͷ� ��� �κ� ä���ֱ�
			// ���� �κ��� int* �̶��
			if (current->level == dim - 1) { // 2�����϶�
				current->next = new int[size[current->level]];
				return;
			}
			// �ƴ϶��
			current->next = new Address[size[current->level]];
			for (int i = 0; i != size[current->level]; i++) {
				// current -> next + i �� ���� current -> level + 1 �� �ٲپ��ֱ�
				(static_cast<Address*>(current->next) + i)->level = current->level + 1;
				initialize_address(static_cast<Address*>(current->next) + i);
			}
		}
		void delete_address(Address* current) {
			// ��� �ּҸ� ����� �Լ�
			if (!current) return;
			// current->next�� Address*�� �ƴ� int*��� ����
			for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) {
				delete_address(static_cast<Address*>(current->next) + i);
			}
			delete[] current->next;
		}
		Int operator[](const int index); // ���� ���� �κ�

		~Array() {
			delete_address(top);
			delete[] size;
		}
	};
	
}

int main() {

	return 0;
}