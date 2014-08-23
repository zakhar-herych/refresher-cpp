#include <algorithm>
#include <stdexcept>
#include <vector>

using namespace std;

double median(vector<double> vec){
	size_t size = vec.size();

	if (size==0) {
		throw domain_error("Median of an empty vector");
	}

	sort(vec.begin(), vec.end());
	size_t mid = size / 2;
	return size % 2 == 0 ? (vec[mid-1] + vec[mid])/2 : vec[mid];
}
