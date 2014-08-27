#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "frame.h"
#include "concat.h"
#include "permuted_index.h"

using namespace std;

int main(){
	vector<string> lines;
	string s;
	while(getline(cin, s)){
		lines.push_back(s);
	}
	// Decoration of lines	
	vector<string> decorated_lines = hcat(lines, frame(center(lines)));
	for (size_t i=0; i<decorated_lines.size(); i++){
		cout << decorated_lines[i] << endl;
	}
	cout << endl;

	// Permuted index of lines
	vector<string> permuted_lines = permuted_index(lines);
	for (size_t i=0; i<permuted_lines.size(); i++){
		cout << permuted_lines[i] << endl;
	}
	return 0;
}
