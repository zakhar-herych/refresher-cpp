#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
	cout << "Please, enter the set of numbers "
		"followed by Ctrl+D ";
	vector<double> numbers;
	double x;

	while (cin >> x){
		numbers.push_back(x);
	}
	
	typedef vector<double>::size_type vec_sz;
	vec_sz size = numbers.size();

	if (size==0) {
		cout << "Error: no numbers were entered";
		return 1;
	}

	sort(numbers.begin(), numbers.end());

	double quartile_1 = numbers[size/4];
	double quartile_2 = numbers[size/2];
	double quartile_3 = numbers[size*3/4];

	cout << "The quartiles are: " <<
		quartile_1 << ", " << 
		quartile_2 << ", " << 
		quartile_3 << endl;

	return 0;
}
