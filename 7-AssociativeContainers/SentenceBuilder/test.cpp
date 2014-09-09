#include <iostream>
#include <vector>
#include <string>

#include "grammar.h"

using namespace std;

int main(){
	vector<string> sentence = gen_sentence(read_grammar(cin));
	for (auto i=sentence.begin(); i!=sentence.end(); i++){
		if (i!=sentence.begin()){
			cout << " ";
		}
		cout << *i;
	}
	cout << endl;
	return 0;
}
