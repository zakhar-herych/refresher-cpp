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

struct Student_info {
	string name;
	double midterm, final;
	vector<double> homeworks;
};

bool operator<(const Student_info& lhs, const Student_info& rhs){
	return lhs.name < rhs.name;
}

istream& read_student_info(istream& is, Student_info& info){
	is >> info.name >> info.midterm >> info.final;
	read_homework(is, info.homeworks);
	return is;
}

double calculate_grade(const Student_info& info){
	return calculate_grade(info.midterm, info.final, info.homeworks);
}

int main(){
	cout << "Please enter data for multiple students in format: " << endl;
	cout << "Name \t Midterm grade \t Final grade \t Homework grades" << endl;
	vector<Student_info> students;
	Student_info record;
	size_t max_length = 0;

	while (read_student_info(cin, record)){
		max_length = max(max_length, record.name.size());
		students.push_back(record);
	}

	sort(students.begin(), students.end());

	for (vector<Student_info>::iterator it = students.begin(); it!=students.end(); it++){
		cout << it->name << string(max_length + 1 - it->name.size(),' ');
		try {
			double final_grade = calculate_grade(*it);
			cout << final_grade << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}
