#include <iostream>
// 접근하는거 만들기
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
		class Iterator {
			int* location;
			Array* arr;

			friend Int;

		public:
			Iterator(Array* arr, int* loc = NULL) : arr(arr) {
				location = new int[arr->dim];
				for (int i = 0; i != arr->dim; i++)
					location[i] = (loc != NULL ? loc[i] : 0);
			}
			Iterator(const Iterator& itr) : arr(itr.arr) {
				location = new int[arr->dim];
				for (int i = 0; i != arr->dim; i++) location[i] = itr.location[i];
			}
			~Iterator() { delete[] location; }

			Iterator& operator++() {
				if (location[0] >= arr->size[0]) return (*this);

				bool carry = false; // 받아 올림이 있는지
				int i = arr->dim - 1; // 가장 끝의 level부터 올라가야하므로
				do {
					location[i]++; // 가장 끝 차원의 인덱스 ++
					if (location[i] >= arr->size[i] && i >= 1) { // i가 0이면 안된다. 0이면 begin과 중복
						location[i] -= arr->size[i];
						carry = true;
						i--; // 그 전 배열의 인덱스로 arr[4][3][1]이라면 1에서 3으로 이동시키기 위함
					}
					else
					{
						carry = false;
					} 
				} while (i >= 0 && carry);
				return (*this);
			}
			Iterator& operator=(const Iterator& itr) {
				arr = itr.arr;
				location = new int[itr.arr->dim];
				for (int i = 0; i != arr->dim; i++) location[i] = itr.location[i];
				return (*this);
			}
			Iterator operator++(int) {
				Iterator itr(*this);
				++(*this);
				return itr;
			}
			bool operator!=(const Iterator& itr) {
				if (itr.arr->dim != arr->dim) return true;

				for (int i = 0; i != arr->dim; i++) {
					if (itr.location[i] != location[i]) return true;
				}

				return false;
			}
			Int operator*();
		};

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

		Iterator begin() {
			int* arr = new int[dim];
			for (int i = 0; i != dim; i++) arr[i] = 0;

			Iterator temp(this, arr);
			delete[] arr;

			return temp;
		}
		Iterator end() {
			int* arr = new int[dim];
			arr[0] = size[0];
			for (int i = 1; i < dim; i++) arr[i] = 0;
			Iterator temp(this, arr);
			delete[] arr;
			return temp;
		}
	};
	class Int {
		void* data;
		int level;
		Array* array;

	public:
		Int(int index, int _level = 0, void* _data = NULL, Array* _array = NULL)
			: level(_level), data(_data), array(_array) {
			if (_level < 1 || index >= array->size[_level - 1]) {
				data = NULL;
				return;
			}
			if (level == array->dim) {
				data = static_cast<void*>((
					static_cast<int*>(static_cast<Array::Address*>(data)->next) + index
					)); // 여기서의 data -> next는 이 전의 level에서의 data -> next인가? O  
			}
			else {
				data = static_cast<void*>(static_cast<Array::Address*>(
					static_cast<Array::Address*>(data)->next) + index);
			}
		};
		Int(const Int& i) : data(i.data), level(i.level), array(i.array) {}

		operator int() {
			if (data) return *static_cast<int*>(data);
			return 0;
		}
		Int& operator=(const int& a) {
			if (data) *static_cast<int*>(data) = a;
			return *this;
		}

		Int operator[](const int index) {
			if (!data) return 0;
			return Int(index, level + 1, data, array);
		}
	};
	Int Array::operator[](const int index) {
		return Int(index, 1, static_cast<void*>(top), this);
	} 
	Int Array::Iterator::operator*() {
		Int start = arr->operator[](location[0]);
		for (int i = 1; i <= arr->dim - 1; i++) {
			start = start.operator[](location[i]);
		}
		return start;
	}
}
// 만들어야 하는 것
// 1. [] 오퍼레이터
// 2. = 오퍼레이터


int main() {
	int size[] = { 2, 3, 4 };
	MyArray::Array arr(3, size);

	MyArray::Array::Iterator itr = arr.begin();
	for (int i = 0; itr != arr.end(); itr++, i++) (*itr) = i;
	for (itr = arr.begin(); itr != arr.end(); itr++)
		std::cout << *itr << std::endl;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 4; k++) {
				arr[i][j][k] = (i + 1) * (j + 1) * (k + 1);
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 4; k++) {
				std::cout << i << " " << j << " " << k << " " << arr[i][j][k] << std::endl;
			}
		}
	}
	return 0;
}