#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std; 

int main(){
	cout << "Please, enter the set of words "
		"followed by Ctrl+D ";
	map<string, int> words_count;
	vector<string> distinct_words;
	string x;
	string min_word="", max_word="";

	while (cin >> x){
		if (words_count.count(x)==0){
			words_count[x] = 1;
			distinct_words.push_back(x);
		}
		else {
			words_count[x] ++;
		}
	}
	for (vector<string>::iterator it = distinct_words.begin(); it!=distinct_words.end(); it++){
		cout <<	*it << ": " << words_count[*it] << endl;
	}
	
	return 0;
}
