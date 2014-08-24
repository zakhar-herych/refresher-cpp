#include <iostream>
#include <vector>

using namespace std;

istream& read_numbers(istream& in, vector<double>& numbers){
	numbers.clear();
	double number;
	
	while (in >> number){
		numbers.push_back(number);
	}
	in.clear();
	return in;
}

double average(const vector<double>& vec){
	if (vec.size()==0){
		return 0;
	}	
	else {
		double sum = 0;
		for (size_t i = 0; i < vec.size(); i++){
			sum += vec[i];
		}
		return sum / vec.size();
	}
}

int main(){
	cout << "Input array of numbers, followed by EOF" << endl;
	vector<double> numbers;
	read_numbers(cin, numbers);
	
	double av = average(numbers);
	cout << "The average of the numbers is: " << av << endl;

	return 0;
}
