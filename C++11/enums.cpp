#include <iostream>

using namespace std;

enum class Options {None, One, All};
int main(){
	Options o = Options::None;
	cout << boolalpha << (o == Options::One) << endl;
	return 0;
}
