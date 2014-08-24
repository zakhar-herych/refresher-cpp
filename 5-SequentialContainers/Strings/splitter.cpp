#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(const string& s){
	vector<string> ret;
	size_t i = 0;
	while (i!=s.size()){
		while (i!=s.size() && isspace(s[i])){
			i++;
		}
		
		size_t j = i;
		while (j!=s.size() && !isspace(s[j])){
			j++;
		}

		if (i!=j){
			ret.push_back(s.substr(i, j-i));
			i = j;
		}
	}
	return ret;
}

