#include <iostream>
#include <vector>
#include <string>
#include "frame.h"

using namespace std;

int main(){
	vector<string> lines;
	string s;
	while(getline(cin, s)){
		lines.push_back(s);
	}
	vector<string> decorated_lines = frame(lines);
	for (size_t i=0; i<decorated_lines.size(); i++){
		cout << decorated_lines[i] << endl;
	}
	return 0;
}
