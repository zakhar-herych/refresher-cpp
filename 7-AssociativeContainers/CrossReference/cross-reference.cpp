#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "split.h"

using namespace std;

map<string, vector<int> > xref(istream& is, vector<string> find_words(const string&)=split){
	string line;
	int line_num = 0;
	map<string, vector<int>> ret;
	while (getline(is,line)){
		line_num ++;
		vector<string> words = find_words(line);
		for (auto word: words){
			ret[word].push_back(line_num);
		}
	}
	return ret;
}

int main(){
	map<string, vector<int> > ref = xref(cin);
	for (auto kw: ref){
		cout << kw.first << "\t";
		for (auto num: kw.second){
			cout << num << " ";
		}
		cout << endl;
	}
	return 0;
}
