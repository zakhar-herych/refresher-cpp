#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	vector<int> u(10, 100);
	vector<int> v;
	for (size_t i=0; i<u.size(); i++){
		cout << u[i] << " ";
	}
	cout << endl;

	copy(u.begin(), u.end(), back_inserter(v));
	for (size_t i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;

	vector<string> words {"Hello", "this", "beautiful", "world"};
	string empty("");
	string result = accumulate(words.begin(), words.end(), empty);
	cout << result << endl;

	return 0;
}
