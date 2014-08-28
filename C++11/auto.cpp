#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

template <typename T, typename E>
auto compose(T a, E b) -> decltype(a+b) {
	return a + b;
}

int main(){
	auto c = compose(2, 3.14);
	cout << c << endl;
	return 0;
}
