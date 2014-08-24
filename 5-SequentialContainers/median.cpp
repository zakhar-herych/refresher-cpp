#include <algorithm>
#include <stdexcept>
#include <list>

using namespace std;

double median(list<double> vec){
	size_t size = vec.size();

	if (size==0) {
		throw domain_error("Median of an empty list");
	}
	vec.sort();
	size_t mid = size / 2;

	list<double>::iterator iter = vec.begin();
	if (size==1){
		return *iter;
	}

	for (size_t i=0; i < mid-1; i++){
		iter++;
	}

	if (size % 2 == 0){
		double sum = *iter++;
		sum += *iter;
		return sum / 2;
	}
	else {
		iter++;
		return *iter;
	}
}
