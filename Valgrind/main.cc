#include <iostream>

int* allocate_int(){
	int* a = new int(2);
	return a;
}

int main(){
	int* x = allocate_int();
	std::cout << x;
	return 0;
}
