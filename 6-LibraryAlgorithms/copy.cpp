#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> src { 1, 2, 3, 4, 5 };
	vector<int> dst { 6, 7, 8 };
	
	// Using "copy" function
	copy(src.begin(), src.begin()+2, back_inserter(dst));
	for (vector<int>::const_iterator it = dst.begin(); it!=dst.end(); it++){
		cout << *it << " ";
	}
	
	return 0;
}
