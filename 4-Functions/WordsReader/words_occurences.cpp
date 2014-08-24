#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "words_reader.h"

using namespace std;

int main(){
	vector<string> words; 
	read_words(cin, words);

	map<string, int> words_count;
	for (size_t i=0; i<words.size(); ++i){
		string x = words[i];
		if (words_count.count(x)==0){
			words_count[x] = 1;
		}
		else {
			words_count[x] ++;
		}
	}
	for (map<string, int>::iterator it = words_count.begin(); it!=words_count.end(); it++){
		cout <<	it->first << ": " << it->second << endl;
	}
}
