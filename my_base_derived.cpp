#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Base
{
public:
	Base()
	{	cout << "Base()" << "\n"; }

	Base(const Base& in)
	{
		cout << "Base(cosnt Base& in)" << "\n";
	}

	Base& operator= (const Base& in)
	{
		if (this == &in)
			return *this;
		cout << "operator= (cosnt Base& in)" << "\n";
	}

	Base(Base&& in)
	{
		cout << "move Base(Base&& in)" << "\n";
	}

	Base& operator= (Base&& in)
	{
		if (this == &in)
			return *this;
		cout << "move operator= (Base&& in)" << "\n";
	}

	virtual void output() const { cout << "Base::output()" << "\n"; }

	void test() const { cout << "Base::test()" << "\n"; }

	virtual ~Base()
	{	cout << "Destructor ~Base()" << "\n"; }
};

class Derived final : public Base
{
public:
	Derived()
	{	cout << "Derived()" << "\n"; }

	Derived(const Derived& in) : Base(in)
	{
		cout << "Derived(cosnt Derived& in)" << "\n";
	}

	Derived& operator= (const Derived& in)
	{
		if (this == &in)
			return *this;
		Base::operator=(in);
		cout << "operator= (const Derived& in)" << "\n";
	}

	Derived(Derived&& in) : Base(move(in))
	{
		cout << "move Derived(Derived&& in)" << "\n";
	}

	Derived& operator= (Derived&& in)
	{
		if (this == &in)
			return *this;
		Base::operator=(move(in));
		cout << "move operator= (Derived&& in)" << "\n";
	}

	virtual void output() const override final { cout << "Derived::output()" << "\n"; }

	virtual ~Derived()
	{	cout << "Destructor ~Derived()" << "\n"; }
};


void my_base_derived_01();
void my_base_derived_02();

void my_base_derived() {
	//my_base_derived_01();
	//my_base_derived_02();
}

void my_base_derived_01() {
	cout << "\nA1\n";
	{
		Derived t1;
		Derived t2(t1);
		Derived t3(move(t1));
	}
	cout << "\nA2\n";
	{
		Derived t1;
		Derived&& rT = move(t1);
		Derived t2 (rT);
		Derived t3 (rT);
	}
	cout << "\nB1\n";
	{
		Derived t1;
		t1.test();
		Derived t_10;
		Base &rBase = t1;
		Derived &rDer = t_10;
		cout << "----\n";
		rDer = t1;
		Base t2;
		rBase = t2;
		rBase = t_10;
	}
	cout << "\nA3\n";
	{
		Derived t1;
		Derived t2 = move(t1);
	}
	cout << "\nA4\n";
	{
		Derived t1;
		Derived t2;
		t2 = move(t1);
	}
	cout << "\n a \n";
	vector<shared_ptr<Derived>> vec;
	vec.emplace_back(make_shared<Derived>());
	vec.emplace_back(make_shared<Derived>());
	for(auto &element : vec) {
		element->output();
	}
	cout << "b \n";
}

////////////////////////////////////////////////////////////

class A
{
public:
	virtual void output() { cout << "A::output()" << "\n"; }
};

class B : public A
{
public:
	virtual void output() { cout << "B::output()" << "\n"; }
};

class C : protected A
{
public:
	virtual void output() { cout << "C::output()" << "\n"; }
};

void my_base_derived_02()
{
	A *pA = new B();
	//pA->output();
	delete pA;
	// Error:
	// A *pA_02 = new C();
	// delete pA_02;
}


