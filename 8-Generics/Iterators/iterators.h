#ifndef ITERATORS_H_
#define ITERATORS_H_

#include <iostream>
#include <algorithm>
#include <iterator>

template<class X, typename Y>
X find_iter(X begin, X end, const Y& y){
	while (begin!=end && *begin!=y){
		++begin;
	}
	return begin;
}

template<class X, class Y>
Y copy_iter(X begin, X end, Y dest){
	while (begin!=end){
		*dest++ = *begin++;
	}
	return dest;
}

template<class X, class Y>
void replace_iter(X begin, X end, const Y& y1, const Y& y2){
	while (begin!=end){
		if (*begin == y1){
			*begin = y2;
		}
		++begin;
	}
}

template<class X>
void reverse_iter(X begin, X end){
	// Move one iterator forward and one backward
	while (begin!=end){
		// Start with the last element
		--end;
		if (begin!=end){
			std::swap(*begin++, *end);
		}
	}
}

template<class X, class Y>
bool binary_search_iter(X begin, X end, const Y& y){
	while (begin < end){
		X mid = begin + (end-begin) / 2;
		if (*mid == y){
			return true;
		}
		else if (*mid < y){
			begin = mid;
		}
		else {
			end = mid;
		}
	}
	return false;
}

template<class X, class Y>
void read_iter(X& container){
	std::copy(std::istream_iterator<Y> (std::cin), std::istream_iterator<Y>(), std::back_inserter(container));
}

template<class X, class Y>
void write_iter(X& container){
	std::copy(begin(container), end(container), std::ostream_iterator<Y> (std::cout, " "));
}

template<class X>
void split_iter(const std::string& s, X out){
	std::string::const_iterator i = s.begin();
	while (i != s.end()){
		i = std::find_if(i, s.end(), [] (char c) {return !std::isspace(c);});
		std::string::const_iterator j = std::find_if(i, s.end(), [] (char c) {return std::isspace(c);});
		if (i!=s.end()){
			*out++ = std::string(i, j);
		}
		i = j;
	}
}

#endif // ITERATORS_H_
