#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
	const int count = 10000;
	stringstream ss;
	ss << count; 
	string count_str = ss.str();
	
	for (int i = 1; i <= count; i++){
		cout << setw(count_str.size()) << i << " " << setw(count_str.size()*2-1) << i*i << endl;
	}
	return 0;
}
