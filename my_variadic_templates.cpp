#include <cstdint>
#include <iostream>
#include <string>
#include <typeinfo>

template<typename T>
T adder(T v)
{	std::cout << __PRETTY_FUNCTION__ << "\n";
	return v;
}

template<typename T, typename ... Ars>
T adder(T first, Ars ... args)
{	std::cout << __PRETTY_FUNCTION__ << "\n";
	return first + adder(args...);
}

static int iCounter = 0;

template<typename... Ars>
void adderSecond(Ars... args)
{	std::cout << __PRETTY_FUNCTION__ << "\n";
	++iCounter;
	std::cout << "iCounter = " << iCounter << " The last one.\n";
}

template<typename T, typename ... Ars>
void adderSecond(T first, Ars ... args)
{	std::cout << __PRETTY_FUNCTION__ << "\n";
	++iCounter;
	std::cout << "iCounter = " << iCounter << "\n";
	return adderSecond(args...);
}


template <class... Ts> struct VariadicTemplates {};

template <class T, class... Ts>
struct VariadicTemplates<T, Ts...> : VariadicTemplates<Ts...> {
	VariadicTemplates(T t, Ts... ts) :
		VariadicTemplates<Ts...>(ts...), tail(t) {}

  T tail;
};
/*
template <size_t, class> struct elem_type_holder;

template <class T, class... Ts>
struct elem_type_holder<0, VariadicTemplates<T, Ts...>> {
  typedef T type;
};

template <size_t k, class T, class... Ts>
struct elem_type_holder<k, VariadicTemplates<T, Ts...>> {
  typedef typename elem_type_holder<k - 1, VariadicTemplates<Ts...>>::type type;
};

template <size_t k, class... Ts>
typename std::enable_if<
    k == 0, typename elem_type_holder<0, VariadicTemplates<Ts...>>::type&>::type
get(VariadicTemplates<Ts...>& t) {
  return t.tail;
}

template <size_t k, class T, class... Ts>
typename std::enable_if<
    k != 0, typename elem_type_holder<k, VariadicTemplates<T, Ts...>>::type&>::type
get(VariadicTemplates<T, Ts...>& t) {
	VariadicTemplates<Ts...>& base = t;
  return get<k - 1>(base);
}
*/
void my_variadic_templates_01();
//https://eli.thegreenplace.net/2014/variadic-templates-in-c/
void my_variadic_templates() {
	my_variadic_templates_01();
}

void my_variadic_templates_01() {
	std::string s1 = "S01", s2 = "S02", s11 = "S11", s12 = "S12";

	std::string res = adder(s1, s2, s11, s12);
	std::cout << "res = " << res << "\n";

	adderSecond(s1, s2, s11, s12);

	VariadicTemplates<double> vt1(12.2);
	std::cout << "sizeof (VariadicTemplates) = " << sizeof(vt1) << "\n";
	VariadicTemplates<double, int> vt2(12.2, 42);
	std::cout << "sizeof (VariadicTemplates) = " << sizeof(vt2) << "\n";
	VariadicTemplates<double, int, const char*> vt3(12.2, 42, "One two three");
	std::cout << "sizeof (VariadicTemplates) = " << sizeof(vt3) << "\n";
}
