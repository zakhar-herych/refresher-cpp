#ifndef _grading_h
#define _grading_h

#include <vector>
#include "student_info.h"

double calculate_grade(double, double, double);
double calculate_grade(double, double, const std::vector<double>&);
double calculate_grade(const Student_info&);
bool failed(const Student_info&);
container extract_failed(container& students);

#endif
