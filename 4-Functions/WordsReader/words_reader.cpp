#include <iostream>
#include <vector>
#include <string>

using namespace std;

istream& read_words(istream& in, vector<string>& words){
	string word;
	while (in >> word){
		words.push_back(word);
	}
	return in;
}
