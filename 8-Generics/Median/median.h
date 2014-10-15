#ifndef MEDIAN_H_
#define MEDIAN_H_

#include <vector>
#include <stdexcept>
#include <algorithm>

template<typename T>
T median(std::vector<T> v){
	size_t size = v.size();
	if (size==0){
		throw std::domain_error("Median of an empty vector");
	}	
	sort(begin(v), end(v));
	size_t mid = size / 2;
	return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

#endif // MEDIAN_H_
