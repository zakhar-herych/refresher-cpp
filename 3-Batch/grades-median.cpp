#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin; 
using std::cout; 
using std::setprecision;
using std::endl; 
using std::string;
using std::streamsize;
using std::vector;
using std::sort;

int main(){
	string name;
	cout << "Please, enter your name: ";
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	cout << "Please, enter your midterm and final grades ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Please, enter the homework grades,"
		"followed by Ctrl+D ";
	vector<double> homework;
	double x;

	while (cin >> x){
		homework.push_back(x);
	}
	
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();

	if (size==0) {
		cout << "Error: no grades were entered";
		return 1;
	}

	sort(homework.begin(), homework.end());

	double median = size % 2 == 0 ? (homework[size/2-1] + homework[size/2])/2 : homework[size/2];
	streamsize prec = cout.precision();
	cout << endl << "The final grade is " << setprecision(3) 
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) << endl;

	return 0;
}
