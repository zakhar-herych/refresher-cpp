#include <vector>
#include <string>
#include "frame.h"

using namespace std;

vector<string> vcat(const vector<string>& top, const vector<string>& bottom){
	vector<string> ret = top;
	ret.insert(ret.end(), bottom.begin(), bottom.end());
	return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right, bool align_right){
	vector<string> ret;

	size_t width_left = frame_width(left);

	size_t i = 0, j = 0;
	while (i!=left.size() || j!=right.size()){
		string line;
		if (i!=left.size()){
			line = left[i++];
		}
		if (align_right){
			line = string(width_left - line.size(), ' ') + line;
		}
		else {
			line += string(width_left - line.size(), ' ');
		}

		if (j!=right.size()){
			line += right[j++];
		}

		ret.push_back(line);
	}
	return ret;
}
