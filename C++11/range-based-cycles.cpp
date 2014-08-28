#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

int main(){
	map<string, vector<int>> m;
	vector<int> v1 {1, 2, 3};
	vector<int> v2 {4, 5, 6};
	m["a"] = v1;
	m["b"] = v2;
	for (auto& kvp: m){
		cout << kvp.first << ": ";
		for (auto& v: kvp.second){
			v *= v;
			cout << v << " ";
		}
		cout << endl;
	}
	copy(m["a"].begin(), m["a"].end(), ostream_iterator<int>(cout, " "));
	copy(m["b"].begin(), m["b"].end(), ostream_iterator<int>(cout, " "));
	return 0;
}
