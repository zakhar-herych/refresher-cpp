#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 

int main(){
	cout << "Please, enter the set of words "
		"followed by Ctrl+D ";
	string x;
	string min_word="", max_word="";

	while (cin >> x){
		if (min_word=="" && max_word==""){
			min_word = x;
			max_word = x;
		}
		else if (x.size() < min_word.size()){
			min_word = x;
		}
		else if (x.size() > max_word.size()){
			max_word = x;
		}
	}
	cout << "The minimal length word is: " << min_word << endl;
	cout << "The maximal length word is: " << max_word << endl;
	
	return 0;
}
