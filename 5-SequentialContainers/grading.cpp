#include <stdexcept>
#include <list>
#include "grading.h"
#include "median.h"
#include "student_info.h"

using namespace std;

double calculate_grade(double midterm, double final, double homework){
	return 0.4 * final + 0.2 * midterm + 0.4 * homework;
}

double calculate_grade(double midterm, double final, const list<double>& homeworks){
	if (homeworks.size()==0){
		throw domain_error("Student has submitted no homeworks");
	}
	return calculate_grade(midterm, final, median(homeworks));
}

double calculate_grade(const Student_info& info){
	return calculate_grade(info.midterm, info.final, info.homeworks);
}

bool failed(const Student_info& info){
	return calculate_grade(info) < 60;
}

list<Student_info> extract_failed(list<Student_info>& students){
	list<Student_info> failed_students;
	list<Student_info>::iterator iter = students.begin(); 
	while (iter != students.end()){
		if (failed(*iter)){
			failed_students.push_back(*iter);
			iter = students.erase(iter);
		} 
		else {
			++iter;
		}
	}
	return failed_students;
}
