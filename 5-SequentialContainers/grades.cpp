#include <stdexcept>
#include <algorithm>
#include "grading.h"

using namespace std;

int main(){
	cout << "Please enter data for multiple students in format: " << endl;
	cout << "Name\tMidterm grade\tFinal grade\tHomework grades" << endl;
	list<Student_info> students;
	Student_info record;
	size_t max_length = 0;

	// Read all the students data to list
	while (read_student_info(cin, record)){
		// Find length of the longest name for proper tabulation
		max_length = max(max_length, record.name.size());
		students.push_back(record);
	}

	list<Student_info> failed = extract_failed(students);

	// Sort list in alphabetical order
	students.sort();

	for (list<Student_info>::iterator it = students.begin(); it!=students.end(); it++){
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
