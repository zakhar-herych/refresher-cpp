#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class B {
public:
	virtual void f(int i) final { cout << "B::f" << endl; };
};

class D : public B {
public:
	// Shouldn't compile for not overriding final
	virtual void f(int i) override { cout << "D::f" << endl; };
};


int main(){
	B* b = new D();
	b->f(1);
	return 0;
}
