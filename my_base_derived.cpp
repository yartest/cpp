#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

void my_base_derived_01();
void my_base_derived_02();

void my_base_derived() {
    //my_base_derived_01();
    //my_base_derived_02();
}

class Base
{
public:
    Base()
    {    cout << "Base()" << "\n"; }

    Base(const Base& in)
    {
        cout << "Base(cosnt Base& in)" << "\n";
    }

    Base& operator= (const Base& in)
    {
        if (this == &in)
            return *this;
        cout << "operator= (cosnt Base& in)" << "\n";
        return *this;
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
        return *this;
    }

    virtual void output() const { cout << "Base::output()" << "\n"; }

    void test() const { cout << "Base::test()" << "\n"; }

    virtual ~Base()
    {    cout << "Destructor ~Base()" << "\n"; }
};

class Derived final : public Base
{
public:
    Derived()
    {    cout << "Derived()" << "\n"; }

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
        return *this;
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
        return *this;
    }

    virtual void output() const override final { cout << "Derived::output()" << "\n"; }

    void test() const { cout << "Derived::test()" << "\n"; }

    virtual ~Derived()
    {    cout << "Destructor ~Derived()" << "\n"; }
};

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
        std::cout << "sizeof(Derived&&) = " << sizeof(rT) << "\n";
        Derived t2 (move(rT));
        Derived t3 (rT);
    }
    cout << "\nB1\n";
    {
        Derived t1;
        Derived t_10;
        Base &rBase = t1;
        Derived &rDer = t_10;
        rBase.test();
        rDer.test();
        cout << "----\n";
        rBase = t_10;
        rDer = t1;
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
    vector<shared_ptr<Base>> vec;
    vec.emplace_back(make_shared<Derived>());
    vec.emplace_back(make_shared<Derived>());
    for(const auto &element : vec) {
        element->output();
    }
    cout << "b \n";
}

////////////////////////////////////////////////////////////

class A
{
public:
    virtual void output() { cout << "A::output()" << "\n"; }

    virtual void test() { cout << "A::test()" << "\n"; }

    void print() { cout << "A::print()" << "\n"; }
};

class B : public A
{
public:
    virtual void output() { cout << "B::output()" << "\n"; }

    virtual void test() {
        A::test();
        cout << "B::test()" << "\n";
    }
};

class C : protected A
{
public:
    virtual void output() { cout << "C::output()" << "\n"; }

    virtual void test() {
        A::test();
        cout << "C::test()" << "\n";
    }
};

class D : private A
{
public:
    virtual void output() { cout << "D::output()" << "\n"; }

    virtual void test() {
        A::test();
        cout << "D::test()" << "\n";
    }
};

class D2 : public D
{
public:
    virtual void test() {
        //A::test();        // Error A is inaccessible from here
        D::test();
        cout << "D2::test()" << "\n";
    }
};

void my_base_derived_02()
{
    A *pA_B = new B();
    //A *pA_C = new C();        // Error
    C *pC = new C();
    //A *pA_D = new D();        // Error
    D *pD = new D();

    pA_B->output();
    pC->output();
    pD->output();
    std::cout << "\n";

    pA_B->test();
    pC->test();
    pD->test();
    std::cout << "\n";

    pA_B->print();
    //pC->print();          // Error
    //pD->print();          // Error

    delete pA_B;
    delete pC;
    delete pD;
}
