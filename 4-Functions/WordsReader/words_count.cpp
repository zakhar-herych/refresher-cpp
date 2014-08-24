#include <string>
#include <iostream>
#include <vector>
#include "words_reader.h"

using namespace std;

int main(){
	vector<string> words; 
	read_words(cin, words);
	cout << "There are total of " << words.size() << " words" << endl;
}
