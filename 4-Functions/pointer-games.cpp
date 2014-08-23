#include<iostream>
#include<vector>

using namespace std;

int main(){
	typedef int* int_star;
	vector<int_star> vec;
	int* a = new int(2);
	int* b = new int(3);
	vec.push_back(a);
	vec.push_back(b);
	for (vector<int_star>::iterator it = vec.begin(); it!=vec.end(); it++){
		cout << *it << ": " << **it << endl;
	}
	
	const vector<int_star>& vec_copy = vec;
	int* c = vec_copy[0];
	*c = 4;
	for (vector<int_star>::iterator it = vec.begin(); it!=vec.end(); it++){
		cout << *it << ": " << **it << endl;
	}
	return 0;
}
