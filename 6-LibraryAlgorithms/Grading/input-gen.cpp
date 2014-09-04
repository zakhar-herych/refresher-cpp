#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
	if (argc < 2){
		cerr << "Usage: " << argv[0] << "numRows" << endl;
		return 1;
	}

	size_t rows_count = atoi(argv[1]);
	vector<string> first_name {"Zakhar", "Ivan", "Petr", "Oleg", "Sergey", "Kirill", "Alexandr", "Alexey", "Albert", "Andrey", "Anton", "Arkadiy", "Artur", "Bogdan", "Boris", "Bulat", "Vadim", "Valeriy", "Vasiliy", "Viktor", "Vladimir", "Vladislav"};
	srand(time(NULL));
	const int homeworks_count = 11;

	for (size_t i = 0; i < rows_count; i++){
		size_t index1 = rand() % first_name.size();
		size_t index2 = rand() % first_name.size();
		size_t index3 = rand() % first_name.size();
		string name = first_name[index1]+"ov"+first_name[index2]+first_name[index3]+"ovich";
		int midterm = rand() % 50 + 51;
		int final = rand() % 50 + 51;
		cout << name << " " << midterm << " " << final;
		for (size_t j = 0; j < homeworks_count; j++){
			int homework_grade = rand() % 50 + 51;
			homework_grade = homework_grade < 55 ? 0: homework_grade;
			cout << " " << homework_grade;
		}
		cout << endl;
	}
	return 0;
}
