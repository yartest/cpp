#include <iostream>
#include <string>
#include <algorithm> // reverse()
#include <sstream> // in the end getline()

using namespace std;

void string_constructors();
void string_append();
void string_assign();
void string_at_resize_capacity_reverse();
void string_compare_copy_erase();
void string_find();
void string_insert();
void string_replace();
void string_substr_swap();
//http://www.martinbroadhurst.com/how-to-split-a-string-in-c.html
void string_processing_01(); // split int to string
void string_processing_02(); // split int to string
void string_processing_03(); // split int to string

void string_functions() {
	//string_constructors();
	//string_append();
	//string_assign();
	//string_at_resize_capacity_reverse();
	//string_compare_copy_erase();
	//string_find();
	//string_insert();
	//string_replace();
	//string_substr_swap();
	//string_processing_01(); // split int to string
	//string_processing_02(); // split int to string
	//string_processing_03(); // split int to string
	//http://www.martinbroadhurst.com/how-to-split-a-string-in-c.html
}

void string_constructors() {
	char *line = "short line for testing";
	string s1;
	s1 = "Description";
	cout << "s1: " << s1 << endl;
	string s2(s1);
	cout << "s2: " << s2 << endl;
	string s3(line);
	cout << "s3: " << s3 << endl;
	// 2 - number of characters
	string s4(line, 10);
	cout << "s4: " << s4 << endl;
	// 2 - start position
	// 3 - number of characters
	string s5(s3, 6, 4); // copy word 'line' from s3
	cout << "s5: " << s5 << endl;
	// 1 - number characters
	// 2 - character itself
	string s6(15, '*');
	cout << "s6: " << s6 << endl;
	// 1 - start iterator
	// 2 - end iterator
	string s7 (s3.begin(), s3.end() - 5);
	cout << "s7: " << s7 << endl;
}

void string_append() {

	string str = "Nobody is perfect";
	string s   = ""; // empty string
	char *ch   = "abcdef";
	s.append(str, 0, 6);
	cout << "s(1): " << s << endl;
	string::iterator inpIt1 = str.begin() + 6;
							//start from " is"
	string::iterator inpIt2 = str.end();
	s.append(inpIt1, inpIt2);
	cout << "s(2): " << s << endl;
	s.append(3, '!');
	cout << "s(3): " << s << endl;
	s.append(ch, 3);
	cout << "s(4): " << s << endl;
}

void string_assign() {

	string str = "Nobody is perfect";
	string s   = "";
	char *ch   = "Robert Frost";
	s.assign(str);
	cout << "s(11): " << s << endl;
	s.assign(str,10,7); // perfect
	cout << "s(2): " << s << endl;
	s.assign(ch, 6);
	cout << "s(3): " << s << endl;
	s.assign(ch);
	cout << "s(4): " << s << endl;
	s.assign(str.begin(),str.end());
	cout << "s(5): " << s << endl;
	s.assign(17, '*');
    cout << "s(6): " << s << endl;

}

void string_at_resize_capacity_reverse() {
	string s = "Nobody is perfect";
    for ( int pos = 0; pos < s.length(); ++pos )
    	cout << s.at(pos) << " ";
    cout << endl;
    reverse(s.begin(), s.end());
    for ( int pos = 0; pos < s.size(); ++pos )
    	cout << s[pos] << " ";
    cout << endl;

	string str = "C++";
	cout << "Capacity of str is: " << str.capacity() << endl;
	cout << "Size of str is    : " << str.size() << endl;
	cout << "Length of str is  : " << str.length() << endl;
	cout << "Resize the str for 50 character" << endl;
	str.resize(50);
	cout << "Capacity of str is: " << str.capacity() << endl;
	cout << "Size of str is    : " << str.size() << endl;
	cout << "Length of str is  : " << str.length() << endl;
}

void string_compare_copy_erase() {
	string str1 = "string";
	string str2 = "String1";
	int compare = str1.compare(str2);
	if (!compare)
		cout << "str1 is equal str2" << endl;
	else
		cout << "str1 is not equal str2" << endl;

	string str = "First Name: Robert", s;
	char fname[255];
	cout << "str: " << str << endl;
	int n = str.find(':');
	str.copy(fname,   // copy to array
			n + 1,    // how many char
			0);       // start position from str
	fname[n+1] = 0;
	cout << "fname: " << fname << endl << endl;

	str = "";
	for(char ch = 'a'; ch <= 'z'; ch++ )
		str.append(1, ch);

	s = str;
	cout << "str: " << str << endl;
	cout << "s: " << s << endl;

    str.erase(0, 13);
    cout << "Erased range fron str: " << str << endl;
    str = s.erase(13, 13);
    cout << "Erased range from s: " << str << endl << endl;
	cout << "Erase one, second character from s" << endl;
	s.erase(s.begin() + 1);
	cout << "s: " << s << endl;
	s.erase(s.begin(), s.begin() + 4);
	cout << "s: " << s << endl;
}

void string_find() {
	string  str("C++ is best language");
	size_t pos1, pos2;
	pos1 = str.find ("best");
	cout << "Word \"best\" is found on position: " << pos1 + 1 << endl;
	pos2 = str.find ("best", pos1 + 1);
	cout << "Word best is found on position: " << pos2 + 1 << endl;
	if (pos2 == string::npos) {
		cout << "not found" << endl;
	}
    pos1 = str.find('+');
    cout << "First character '+' found on position: " << pos1 + 1 << endl << endl;

	pos1 = str.find_first_not_of("aeiouAEIOUCs+", 8);
	cout << "First consonant found at " << pos1 + 1 << " position" << endl << endl;

	pos1 = str.find_first_of(" bae", 0);
	cout << "First consonant found at " << pos1 + 1 << " position" << endl << endl;
	//				find_last_not_of
	//				find_last_of
}

void string_insert() {
	string str = "C++ language";
	string s   = "is best";
	char ch[]  = "C++ language";
	cout << "str: " << str << endl;
	cout << "s: " << s.c_str() << endl;
	cout << "ch: " << ch << endl;
	size_t pos = 4;
	str.insert(pos, s);
	cout << "str 123: " << str << endl;
	pos = str.find('l');
	str.insert(str.begin() + pos, ' ');
    cout << "str: " << str << endl;
	str.insert(str.end(), 3, '!');
	cout << "str 000: " << str << endl << endl;
    s.insert(0, ch, 4);
    cout << "s: " << s << endl;
	pos = str.find('l');
	int x = s.length();
	s.insert(x, str, pos, 8);
	cout << "s: " << s   << endl;
	pos = s.find('l');
	s.insert(s.begin() + pos, ' ');
	cout << "s   is: " << s   << endl;
    s.insert(s.begin() + 4, str.begin(), str.begin() + 7);
    cout << "s   is: " << s   << endl;
}

void string_replace() {
	string str = "STL is created from Dennis Ritchie";
	string s1  = "was";
	string s2  = "developed";
	string s3  = "Stepanov Alexander";
	cout << "str: " << str << endl;
    cout << "replace 'is' for 'was'" << endl;
    str.replace(4, // start position in str
            2,     // how many characters
            s1);   // source for replacement
    cout << "str: " << str << endl;
    cout << "replace 'created' for 'developed'" << endl;
    size_t n = str.find('c'); // pos of 'created'
    size_t x = str.find("from") - 1;
    str.replace(str.begin() + n,  // start pointer
    			str.begin() + x,  // end pointer
				s2);              // source
    cout << "str: " << str << endl << endl;

    cout << "replace 'Dennis' for 'Alexander'" << endl;
    size_t x1 = str.find('D'); // search Dennis
    size_t x2 = str.find(' ', x1 + 1); // space after
    size_t y1 = s3.find("Alex"); // search 'alex'
    size_t y2 = sizeof("Alexander") - 1;
    str.replace(x1, // start position in str
            x2 - x1,  // how characters to replace
            s3,     // source for replacement
            y1,     // start position from source
            y2);    // how chracter start from y1
    cout << "str: " << str << endl;

    cout << "replace 'from' for 'by'" << endl;
    char ary[] = "bytes";
    n = str.find("from");
    str.replace(n, // start position in str
            4,     // how many characters
            ary,   // source
            2);    // first 2 characters from source
    cout << "str: " << str << endl << endl;

    cout << "replace 'A' for 'a' (Alexander)" << endl;
    n = str.find("Alexander");
    str.replace(n,  // start position in str
            1,      // how character(s)
            1,      // how many copies of character
            'a');   // character for replasment
    cout << "str: " << str << endl;

    cout << "replace 'Ritchie' for 'Stepanov'" << endl;
    x1 = str.find('R');
    y1 = s3.find(' ');

    str.replace(str.begin() + x1, // start pointer
            str.end(), // to the end of str
            s3.begin(), // start pointer from source
            s3.begin() + y1); // end pointer from source
    cout << "str: " << str << endl;
}

void string_substr_swap() {
    string str = "We go step by step to the target", str2 = "Test";
    cout << "str: " << str << endl;
    int n = str.find("step");
    string s = str.substr(n);
    cout << "s: " << s << endl;
    s = str.substr(n, 12);
    cout << "s: " << s << endl;

	str.swap(str2);
    cout << "str: " << str << endl;
    cout << "str2: " << str2 << endl;
}

void string_processing_01() {
	string input = "145;24;32;";
	stringstream ss(input);
	string part;
	int number;
	stringstream s_part;
	string error_msg("convert error");

	while(std::getline(ss, part, ';')) {
	    std::cout << part << endl;
	    s_part << part;
	    if( (s_part >> number).fail() ) {
	    	throw error_msg;
	    }
	    cout << "number = " << number << endl;
	    //number = stoi(part); //C++11 only
	    s_part.clear();
	}
	// example from int to string
	string test;
	s_part << number;
	s_part >> test;
	cout << "test = " << test << endl;
	// example from string to int
	s_part.clear();
	s_part << test;
	if ( (s_part >> number).fail() )
		throw error_msg;
	cout << "number = " << number << endl << endl;
}

void string_processing_02() {
	string input = "145;;24;;32;;";
	string delimiter = ";;";

	size_t pos = 0;
	string part;
	while ((pos = input.find(delimiter)) != string::npos) {
		part = input.substr(0, pos);
		cout << part << "~~~";
		input.erase(0, pos + delimiter.length());
	}
	cout << endl;
}

void string_processing_03() {
	string input = "145;;24;;32;;";
	string delimiter = ";;";

	size_t posFirst = 0, posLast = 0;
	string part;
	while ((posLast = input.find(delimiter, posFirst)) != string::npos) {
		part = input.substr(posFirst, (posLast - posFirst));
		cout << part << "+++";
		posFirst = posLast + delimiter.length();
	}
}

