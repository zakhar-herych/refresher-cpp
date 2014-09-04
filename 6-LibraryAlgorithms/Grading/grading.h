#ifndef _grading_h
#define _grading_h

#include <vector>
#include "student_info.h"

double calculate_grade(double, double, double);
double calculate_grade(double, double, const std::vector<double>&);
double calculate_grade(const Student_info&);
bool failed(const Student_info&);
container extract_failed(container& students);

double median_analysis(const std::vector<Student_info>& students);
double average_analysis(const std::vector<Student_info>& students);
double optimistic_median_analysis(const std::vector<Student_info>& students);

void write_analysis(std::ostream& out, const std::string& name,
		double analysis(const std::vector<Student_info>&),
		const std::vector<Student_info>& did, const std::vector<Student_info>& didnt);
#endif
