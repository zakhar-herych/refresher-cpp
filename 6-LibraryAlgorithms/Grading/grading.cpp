#include <stdexcept>
#include <vector>
#include <list>
#include "grading.h"
#include "math.h"
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

bool passed(const Student_info& info){
	return !failed(info);
}

container extract_failed2(container& students){
	container failed_students;
	container::iterator iter = students.begin(); 
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

container extract_failed3(container& students){
	container failed_students;
	remove_copy_if(students.begin(), students.end(), back_inserter(failed_students), passed);
	students.erase(remove_if(students.begin(), students.end(), failed), students.end());
	return failed_students;
}

container extract_failed(container& students){
	container::iterator iter = stable_partition(students.begin(), students.end(), passed);
	container failed_students(iter, students.end());
	students.erase(iter, students.end());
	return failed_students;
}

double grade_aux(const Student_info& s){
	try {
		return calculate_grade(s);
	}
	catch (domain_error) {
		return calculate_grade(s.midterm, s.final, 0);
	}
}

double average_grade(const Student_info& s) {
	return calculate_grade(s.midterm, s.final, average(s.homeworks));
}

double optimistic_median(const Student_info& s) {
	vector<double> nonzero;
	remove_copy(s.homeworks.begin(), s.homeworks.end(), back_inserter(nonzero), 0);
	if (nonzero.empty()){
		return calculate_grade(s.midterm, s.final, 0);
	}
	else {
		return calculate_grade(s.midterm, s.final, median(nonzero));
	}
}

double median_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

double average_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), average_grade);
	return median(grades);
}

double optimistic_median_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
	return median(grades);
}

void write_analysis(ostream& out, const string& name,
		double analysis(const vector<Student_info>&),
		const vector<Student_info>& did, const vector<Student_info>& didnt) {
	out << name << ": median(did) = " << analysis(did) <<
		", median(didnt) = " << analysis(didnt) << endl;
}

