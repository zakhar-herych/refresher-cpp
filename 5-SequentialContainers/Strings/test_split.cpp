#include <iostream>
#include <vector>
#include <string>
#include "splitter.h"

using namespace std;

int main(){
	string s;
	while(getline(cin, s)){
		vector<string> words = split(s);
		for (size_t i = 0; i < words.size(); i++){
			cout << words[i] << endl;
		}
	}
	return 0;
}
