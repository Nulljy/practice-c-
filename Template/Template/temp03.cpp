#include <iostream>

//int sum_all() { return 0; }
//template<typename... Ints>
//int sum_all(int a, Ints... nums) {
//	return a + sum_all(nums...);
//}
//
//template<typename... Ints>
//double average(Ints... nums) {
//	return  static_cast<double>(sum_all(nums...)) / sizeof...(nums);
//}

template<typename... Ints>
//int sum_all(Ints... nums) {
//	return (nums + ...);
//}
//int sum_all(Ints... nums) {
//	return (... + nums);}
int sum_all(int start, Ints... nums) {
	return (start + ... + nums);
}


int main() {
	std::cout << sum_all(100, 3, 2, 1) << std::endl;
	/*std::cout << average(6, 5, 4, 3, 2, 1);*/
	return 0;
}