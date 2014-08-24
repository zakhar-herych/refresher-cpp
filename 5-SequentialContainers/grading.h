#ifndef _grading_h
#define _grading_h

#include <list>
#include "student_info.h"

double calculate_grade(double, double, double);
double calculate_grade(double, double, const std::list<double>&);
double calculate_grade(const Student_info&);
bool failed(const Student_info&);
std::list<Student_info> extract_failed(std::list<Student_info>& students);

#endif
