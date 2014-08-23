#include <stdexcept>
#include <algorithm>
#include "grading.h"

using namespace std;

int main(){
	cout << "Please enter data for multiple students in format: " << endl;
	cout << "Name\tMidterm grade\tFinal grade\tHomework grades" << endl;
	vector<Student_info> students;
	Student_info record;
	size_t max_length = 0;

	// Read all the students data to vector
	while (read_student_info(cin, record)){
		// Find length of the longest name for proper tabulation
		max_length = max(max_length, record.name.size());
		students.push_back(record);
	}

	// Sort vector in alphabetical order
	sort(students.begin(), students.end());

	for (vector<Student_info>::iterator it = students.begin(); it!=students.end(); it++){
		cout << it->name << string(max_length + 1 - it->name.size(),' ');
		try {
			// Calculate final grade
			double final_grade = calculate_grade(*it);
			cout << final_grade << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}
