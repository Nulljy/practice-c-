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

			// 함수
			initialize_address(top);
		}
		Array(const Array& arr) : dim(arr.dim) {
			size = new int[dim];
			for (int i = 0; i < dim; i++) {
				size[i] = arr.size[i];
			}
			top = new Address;
			top->level = 0;

			// 함수
			initialize_address(top);
		}
		// {4, 3, 1}
		void initialize_address(Address* current) { // 주소 초기화
			if (!current) return;
			// 재귀로 모든 부분 채워주기
			// 다음 부분이 int* 이라면
			if (current->level == dim - 1) { // 2차원일때
				current->next = new int[size[current->level]];
				return;
			}
			// 아니라면
			current->next = new Address[size[current->level]];
			for (int i = 0; i != size[current->level]; i++) {
				// current -> next + i 의 레벨 current -> level + 1 로 바꾸어주기
				(static_cast<Address*>(current->next) + i)->level = current->level + 1;
				initialize_address(static_cast<Address*>(current->next) + i);
			}
		}
		void delete_address(Address* current) {
			// 모든 주소를 지우는 함수
			if (!current) return;
			// current->next가 Address*가 아닌 int*라면 리턴
			for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) {
				delete_address(static_cast<Address*>(current->next) + i);
			}
			delete[] current->next;
		}
		Int operator[](const int index); // 새로 배우는 부분

		~Array() {
			delete_address(top);
			delete[] size;
		}
	};
	
}

int main() {

	return 0;
}