#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

int main(){
	std::string s;
	std::map<std::string, int> word_count;
	while (std::cin >> s){
		++word_count[s];
	}
	std::vector<std::pair<int,std::string>> items;
	for (auto& it: word_count){
		items.push_back(std::pair<int,std::string>(it.second, it.first));
	}
	sort(begin(items), end(items));
	for (auto& it: items){
		printf("%s:\t%d\n", it.second.c_str(), it.first);
	}
	return 0;
}
