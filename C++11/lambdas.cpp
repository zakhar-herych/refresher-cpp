#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class InitVector{
	public:
		InitVector(int base, int power): m_base(base), m_power(power) {};
		void initVector(vector<int> & v){
			// Lambda for class variables
			for_each(v.begin(), v.end(), [this] (int &val) mutable {
				val = m_base;
				m_base *= m_power;
			});
		}

	private:
		int m_base, m_power;
};

int main(){
	vector<int> vec { 1, 2, 3, 4, 5, 6, 7 };
	
	// Output with lambda
	for_each(vec.begin(), vec.end(), [] (int n) { cout << n << " "; });
	cout << endl << endl;

	// Count with lambda
	cout << count_if(vec.begin(), vec.end(), [] (int n) {return n%2==0;});
	cout << endl << endl;

	// Transform with lambda
	vector<double> dst;
	transform(vec.begin(), vec.end(), back_inserter(dst), [] (int n) -> double { 
		if (n<3) { return n+1.0; }
		else if (n%2==0) { return n/2.0; }
		else { return n*n; }
	});
	copy(dst.begin(), dst.end(), ostream_iterator<double>(cout, " "));
	cout << endl << endl;

	// Lambda with state
	int lower_bound = 3, upper_bound = 6;
	cout << count_if(vec.begin(), vec.end(), [lower_bound, upper_bound] (int n) 
		{return lower_bound <= n && n < upper_bound; });
	cout << endl << endl;

	// Mutable iterators
	vector<int> dst2;
	int count = 0;
	generate_n(back_inserter(dst2), 10, [&count] () mutable { return count++; });
	copy(dst2.begin(), dst2.end(), ostream_iterator<double>(cout, " "));
	cout << endl << "count: " << count;
	cout << endl << endl;

	// Mutable iterators in class
	vector<int> dst3(11);
	InitVector init(1, 2);
	init.initVector(dst3);
	for_each(dst3.begin(), dst3.end(), [] (int n) { cout << n << " "; });
	cout << endl << endl;

	// Saving lambdas
	function<void (int)> trace_lambda = [] (int val) { cout << val << " "; };
	for_each(vec.begin(), vec.end(), trace_lambda);
	cout << endl;
	auto lambda_gen = [] (int val) -> function<int (int)> { return [=] (int n) { return n+val; }; };
	transform(vec.begin(), vec.end(), vec.begin(), lambda_gen(2));
	for_each(vec.begin(), vec.end(), trace_lambda);
	cout << endl << endl;

	// Recursive lambdas
	function<int(int)> fib = [&fib] (int n) { return n < 2? 1 : fib(n-1) + fib(n-2); };
	cout << fib(10);
	cout << endl << endl;
	return 0;
}
