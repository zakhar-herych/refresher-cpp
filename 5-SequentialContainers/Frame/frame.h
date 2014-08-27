#ifndef _splitter_h
#define _splitter_h

#include <vector>
#include <string>

size_t frame_width(const std::vector<std::string>&);
std::vector<std::string> frame(const std::vector<std::string>&);
std::vector<std::string> center(const std::vector<std::string>&);

#endif
