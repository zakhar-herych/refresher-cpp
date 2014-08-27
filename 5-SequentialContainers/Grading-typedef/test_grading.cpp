#include <stdexcept>
#include <algorithm>
#include "grading.h"
#include <chrono>

using namespace std;

int main(){
	cout << "Please enter data for multiple students in format: " << endl;
	cout << "Name\tMidterm grade\tFinal grade\tHomework grades" << endl;
	container students;
	Student_info record;
	size_t max_length = 0;

	// Read all the students data to list
	while (read_student_info(cin, record)){
		// Find length of the longest name for proper tabulation
		max_length = max(max_length, record.name.size());
		students.push_back(record);
	}

	auto start = chrono::high_resolution_clock::now();	
	// ************************************************
	// Time this block
	container failed = extract_failed(students);

	// Sort list in alphabetical order
	sort(students);
	
	// ************************************************
	auto elapsed = chrono::high_resolution_clock::now() - start;

	for (container::iterator it = students.begin(); it!=students.end(); it++){
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

	long long microseconds = chrono::duration_cast<chrono::microseconds>(elapsed).count();
	cout << endl << "Time taken: " << microseconds << endl << endl;

	return 0;
}
