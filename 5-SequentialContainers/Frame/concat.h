#ifndef _vertical_concat_h
#define _vertical_concat_h

#include <vector>
#include <string>

std::vector<std::string> vcat(const std::vector<std::string>& top, const std::vector<std::string>& bottom);
std::vector<std::string> hcat(const std::vector<std::string>& top, const std::vector<std::string>& bottom, bool align_right=true);

#endif
