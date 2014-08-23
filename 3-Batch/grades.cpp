#include <iostream>
#include <string>
#include <vector>

using std::cin; 
using std::cout; 
using std::endl; 
using std::string;
using std::vector;

int main(){
	vector<string> names;
	vector<double> grades;
	const int homework_count = 3;

	string name;
	cout << "Please, enter name: ";
	while (cin >> name) {
		names.push_back(name);
		cout << "Please, enter your midterm and final grades ";
		double midterm, final;
		cin >> midterm >> final;

		cout << "Please, enter ";
		cout << homework_count;
		cout << " homework grades ";
		
		double sum = 0;
		double x;

		for (size_t count = 0; count < homework_count; count ++ ){
			cin >> x;
			sum += x;
		}
		grades.push_back(0.2 * midterm + 0.4 * final + 0.4 * sum / homework_count);
		cout << endl << "Please, enter one more name or press Ctrl+D" << endl;
	}

	cout << endl << "The final grades are: " << endl;
	for (size_t count = 0; count < names.size(); count ++){
		cout << names[count] << ": \t" << grades[count] << endl; 
	}

	return 0;
}
