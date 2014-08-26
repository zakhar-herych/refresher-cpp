#include <vector>
#include <string>
#include <algorithm>
#include "concat.h"

using namespace std;

struct Context {
	string words;
	string words_before;
};

bool operator< (const Context& lhs, const Context& rhs){
	string w1 = lhs.words;
	string w2 = rhs.words;
	transform(w1.begin(), w1.end(), w1.begin(), ::tolower);
	transform(w2.begin(), w2.end(), w2.begin(), ::tolower);
	return w1 < w2;
}

vector<string> permuted_index(const vector<string>& strings){
	vector<Context> contexts;
	for (size_t k=0; k<strings.size(); k++){
		string s = strings[k];
		size_t i=0;
		while (i!=s.size()) {
			while (i!=s.size() && isspace(s[i])){
				i++;
			}
			size_t j=i;
			while (j!=s.size() && !isspace(s[j])){
				j++;
			}
			if (i!=j) {
				Context context;
				context.words_before = s.substr(0, i);
				context.words = s.substr(i, s.size()-i);
				contexts.push_back(context);
				i = j;
			}
		}
	}
	sort(contexts.begin(), contexts.end());
	
	vector<string> first_half;
	vector<string> second_half;
	for (size_t i=0; i<contexts.size(); i++){
		first_half.push_back(contexts[i].words_before + "\t");
		second_half.push_back(contexts[i].words);
	}

    vector<string> ret = hcat(first_half, second_half, true);
	return ret;
}

