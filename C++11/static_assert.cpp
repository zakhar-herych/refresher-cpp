#include <cassert>
#include <iostream>

using namespace std;

template <typename T, size_t size>
struct Vector{
	static_assert(size > 3, "Size is too small");
	T points[size];
};

int main(){
	Vector<int, 16> a1;
	a1.points[0] = 1;
	cout << a1.points[0] << endl;
	// Static assertion fails here 
	//Vector<double, 2> a2;
	return 0;
}
