#include <algorithm>
#include <stdexcept>
#include <numeric>
#include <list>

using namespace std;

double median(vector<double> vec){
	size_t size = vec.size();

	if (size==0) {
		throw domain_error("Median of an empty list");
	}
	sort(vec.begin(), vec.end());
	size_t mid = size / 2;

	return size % 2 == 0 ? (vec[mid-1]+vec[mid])/2 : vec[mid];
}

double average(vector<double> vec){
	return accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
}
