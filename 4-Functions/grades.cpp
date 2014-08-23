#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

double calculate_median(vector<double> vec){
	size_t size = vec.size();

	if (size==0) {
		throw domain_error("Median of an empty vector");
	}

	sort(vec.begin(), vec.end());
	size_t mid = size / 2;

	return size % 2 == 0 ? (vec[mid-1] + vec[mid])/2 : vec[mid];
}

double calculate_grade(double midterm, double final, double homework){
	return 0.4 * final + 0.2 * midterm + 0.4 * homework;
}

double calculate_grade(double midterm, double final, const vector<double>& homeworks){
	if (homeworks.size()==0){
		throw domain_error("Student has submitted no homeworks");
	}
	return calculate_grade(midterm, final, calculate_median(homeworks));
}

istream& read_homework(istream& in, vector<double>& homeworks){
	if (in) {
		homeworks.clear();
		double grade;
		while (in >> grade){
			homeworks.push_back(grade);
		}
		in.clear();
	}
	return in;
}

int main(){
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Enter all your homework grades, followed by end-of-file: ";
	vector<double> homeworks;
	read_homework(cin, homeworks);
	try {
		cout << "Your final grade is: " << calculate_grade(midterm, final, homeworks);
	}
	catch (domain_error) {
		cout << "You entered no grades" << endl;
		return 1;
	}
	return 0;
}
