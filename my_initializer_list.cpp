#include <iostream>
#include <vector>

//using namespace std;

void initializer_list_01();
void initializer_list_02();

void my_initializer_list() {
    //initializer_list_01();
    //initializer_list_02();
}

// https://habr.com/ru/post/330402/
void initializer_list_01() {

	// initializer_list<int> type of y
    auto y = {1, 2, 3, 4, 5, 6, 7};
    std::cout << "sizeof(y) = " << sizeof(y) << "\n";

	const int k = 10;
    std::cout << "k=" << k << "\n\n\n";
    //static_assert(k <= 0, "k is greater than 0, error");
    static_assert(k >= 0, "k is negative, error");
}

////////////////////////////////////////////////////////////

struct InitList__1
{
    double t;
    InitList__1 (int k, int s)
    { std::cout << "InitList__1(int k, int s) k:" << k << ", s:" << s << "\n"; }

    InitList__1 (std::initializer_list<int> &&t)
    {
        std::cout << "InitList__1 (initializer_list<int> &&t) \n";
        for (const auto &element : t)
            std::cout << "InitList element: " << element << "\n";
    }
};

struct InitList__2
{
    double t;
    InitList__2 (int k, int s)
    { std::cout << "InitList__2(int k, int s) k:" << k << ", s:" << s << "\n"; }
};

struct InitList__3
{
    int t;
    char c;
};

void initializer_list_02()
{
    InitList__1 x1{1, 2};
    InitList__1 x2 {3};
    InitList__1 x3(4, 5);
    //InitList__1 x4(6);        // error during compilation

    std::vector <InitList__1> vec;
    //vec.emplace_back(40);         // error during compilation
    //vec.emplace_back({41});       // error during compilation
    vec.emplace_back(42, 43);
    //vec.emplace_back({44, 45});   // error during compilation

    InitList__2 y1{11, 12};
    //InitList__2 y2 {13};      // error during compilation
    InitList__2 y3(14, 15);
    //InitList__2 y4(16);       // error during compilation

    std::vector <InitList__2> vec__2;
    vec__2.emplace_back(70, 71);

    InitList__3 z1{21, 'a'};
    std::cout << "\nz1.t = " << z1.t << "\n";
    std::cout << "z1.c = " << z1.c << "\n";
    //InitList__3 z2(22, 'b');       // error during compilation

    std::vector <InitList__3> vec__3;
    //vec__3.emplace_back(90, 'c');  // error during compilation
}

////////////////////////////////////////////////////////////
