#include <iostream>

using namespace std;

void my_strongly_typed_enums_01();

void my_strongly_typed_enums() {
	my_strongly_typed_enums_01();
}

enum class Options {None, One, All};
ostream& operator<< (ostream& out, Options in)
{
	switch (in)
	{
	case Options::None:
		out << "None";
		break;
	case Options::One:
		out << "One";
		break;
	case Options::All:
		out << "All";
		break;
	}
	return out;
}

void my_strongly_typed_enums_01() {
	Options test = Options::One;
	cout << "Options test = " << test << "\n";
	//Error
	//test = 0;
}
