#include "grammar.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include "split.h"

// Read a grammar from input stream
Grammar read_grammar(std::istream& in){
	Grammar ret;
	std::string line;
	
	while (getline(in, line)){
		std::vector<std::string> entry = split(line);
		if (!entry.empty()){
			// Use category entry[0] to store associated rule
			Rule rule(entry.begin()+1, entry.end());
			ret[entry[0]].push_back(rule);
		}
	}
	return ret;
}

bool bracketed(const std::string& s){
	return s.size()>1 && s[0]=='<' && s[s.size()-1]=='>';
}

// returns a number from 0 to n-1
int nrand(int n){
	if (n<=0 || n>RAND_MAX){
		throw std::domain_error("Argument to nrand is out of range");
	}
	else {
		const int bucket_size = RAND_MAX / n;
		int r;
		do {
			r = rand() / bucket_size;
		} while (r>=n);

		return r;
	}
}

void gen_aux(const Grammar& g, const std::string& token, std::vector<std::string>& ret){
	if (!bracketed(token)){
		ret.push_back(token);
	}
	else {
		Grammar::const_iterator it = g.find(token);
		if (it==g.end()){
			throw std::logic_error("empty rule");
		}
		const Rule_Collection& c = it->second;
		
		const Rule& r = c[nrand(c.size())];

		for (auto i=r.begin(); i!=r.end(); ++i){
			gen_aux(g, *i, ret);
		}
	}
}

// Generate a sentence from a current grammar
std::vector<std::string> gen_sentence(const Grammar& g){
	std::vector<std::string> ret;
	srand(time(nullptr));
	gen_aux(g, "<sentence>", ret);
	return ret;
}
