#ifndef _student_info_h
#define _student_info_h

#include <iostream>
#include <string>
#include <list>

struct Student_info {
	std::string name;
	double midterm, final;
	std::list<double> homeworks;
};

std::istream& read_student_info(std::istream& is, Student_info& info);
std::istream& read_homework(std::istream& in, std::list<double>& homework);
bool operator<(const Student_info& lhs, const Student_info& rhs);

#endif
