#include "student_info.h"

using namespace std;

istream& read_homework(istream& in, list<double>& homeworks){
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

bool operator<(const Student_info& lhs, const Student_info& rhs){
	return lhs.name < rhs.name;
}

istream& read_student_info(istream& is, Student_info& info){
	is >> info.name >> info.midterm >> info.final;
	read_homework(is, info.homeworks);
	return is;
}

