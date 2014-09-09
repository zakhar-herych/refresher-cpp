#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> split(const string& s){
	vector<string> ret;
	string::const_iterator i = s.begin();
	while (i != s.end()){
		i = find_if(i, s.end(), [] (char c) {return !isspace(c);});
		string::const_iterator j = find_if(i, s.end(), [] (char c) {return isspace(c);});
		if (i!=s.end()){
			ret.push_back(string(i, j));
		}
		i = j;
	}
	return ret;
}
