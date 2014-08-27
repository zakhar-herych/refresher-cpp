#include <iostream>
#include <vector>
#include <string>

using namespace std;

size_t frame_width(const vector<string>& vec){
	size_t max_length = 0;
	for (size_t i=0; i<vec.size(); i++) {
		max_length = max(max_length, vec[i].size());
	}
	return max_length;
}

vector<string> frame(const vector<string>& s){
	vector<string> ret;
	int width = frame_width(s);
	size_t pad = 1;
	string border(width + 2*pad + 2, '*');
	ret.push_back(border);
	for (size_t i=0; i<pad; i++){
		string spaces(width + 2*pad, ' ');
		ret.push_back("*" + spaces + "*");
	}
    for (size_t i=0; i<s.size(); i++){
		string spaces(pad, ' ');
		string width_spaces(width - s[i].size(), ' ');
		ret.push_back("*" + spaces + s[i] + width_spaces + spaces + "*");
	}
	for (size_t i=0; i<pad; i++){
		string spaces(width + 2*pad, ' ');
		ret.push_back("*" + spaces + "*");
	}
	ret.push_back(border);
	return ret;
}

vector<string> center(const vector<string>& s){
	vector<string> ret;
	int width = frame_width(s);
	for (size_t i=0; i<s.size(); i++){
		string spaces((width-s[i].size())/2, ' ');
		string spaces2(width-s[i].size()-spaces.size(), ' ');
		ret.push_back(spaces + s[i] + spaces2);
	}
	return ret;
}
