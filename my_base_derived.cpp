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

	virtual ~Base()
	{	cout << "Destructor ~Base()" << "\n"; }
};

class Derived final : Base
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

void my_base_derived() {
	my_base_derived_01();
}

void my_base_derived_01() {
	{
		Derived t1;
		Derived t2(t1);
		Derived t3(move(t1));
	}
	cout << "\n";
	{
		Derived t1;
		Derived&& rT = move(t1);
		Derived t2 (move(rT));
		Derived t3 (rT);
	}
	cout << "\n";
	{
		Derived t1;
		Derived t2 = move(t1);
	}
	cout << "\n";
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
