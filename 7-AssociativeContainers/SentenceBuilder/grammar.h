#ifndef _GRAMMAR_H
#define _GRAMMAR_H

#include <string>
#include <vector>
#include <map>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_Collection;
typedef std::map<std::string, Rule_Collection> Grammar;

Grammar read_grammar(std::istream&);
std::vector<std::string> gen_sentence(const Grammar&);

#endif // _GRAMMAR_H
