#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(){
	// Palindrome lambda
	auto is_palindrome = [] (string s) -> bool { return equal(s.begin(), s.end(), s.rbegin()); };
	vector<string> suspects {"civic", "eye", "a", "ok"};
	for (string& word: suspects){
		cout << word << " is " << (!is_palindrome(word) ? "not " : "") << "a palindrome" << endl;
	}
	
	return 0;
}
