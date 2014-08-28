#include <stdexcept>
#include <vector>
#include <list>
#include "grading.h"
#include "median.h"
#include "student_info.h"

using namespace std;

double calculate_grade(double midterm, double final, double homework){
	return 0.4 * final + 0.2 * midterm + 0.4 * homework;
}

double calculate_grade(double midterm, double final, const vector<double>& homeworks){
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

// works only for vector
container extract_failed(container& students){
	size_t passed = 0;
	container failed_students;
	container::iterator iter = students.begin(); 
	while (iter != students.end()){
		if (failed(*iter)){
			failed_students.push_back(*iter++);
		} 
		else {
			students[passed++] = *iter ++;
		}
	}
	students.resize(passed);
	return failed_students;
}
