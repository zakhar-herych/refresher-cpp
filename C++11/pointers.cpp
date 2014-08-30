#include <iostream>
#include <memory>

using namespace std;

void out(int* ptr){
	cout << *ptr << endl;
}

struct Foo{
	Foo() { cout << "Foo::Foo" << endl; }
	~Foo() { cout << "Foo::~Foo" << endl; }
	void bar() { cout << "Foo::bar" << endl; }
};

void f(const Foo& foo){
	cout << "f(const Foo&)" << endl;
}

int main(){
	unique_ptr<int> p1(new int(42));
	unique_ptr<int> p2 = move(p1);

	if (p1){
		out(p1.get());
	}
	(*p2)++;
	if (p2){
		out(p2.get());
	}

	unique_ptr<Foo> f1(new Foo);
	f1->bar();
	{
		unique_ptr<Foo> f2(move(f1));
		f(*f2);
		f1 = move(f2);
	}
	f1->bar();

	cout << endl;

	shared_ptr<Foo> s1(new Foo);
	shared_ptr<Foo> s2 = s1;

	s1->bar();
	f(*s2);

	return 0;
}
