#ifndef _student_info_h
#define _student_info_h

#include <algorithm>
#include <iostream>
#include <string>
#include <list>
#include <vector>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homeworks;
};

typedef std::list<Student_info> container;

std::istream& read_student_info(std::istream& is, Student_info& info);
std::istream& read_homework(std::istream& in, std::vector<double>& homework);
bool operator<(const Student_info& lhs, const Student_info& rhs);

inline void sort(std::vector<Student_info>& v) { sort(v.begin(), v.end()); } 
inline void sort(std::list<Student_info>& l) { l.sort(); } 

#endif
