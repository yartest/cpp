#include <iostream>
#include <exception>

using namespace std;

void input_output_data();
void input_output_data_c();
void string_functions();
void vector_functions();
void list_functions();
void map_auto_functions();
void my_binary_unary_functions();
void my_variadic_templates();
void my_base_derived();
void my_rvalue_lvalue();
void pointers_functions();
void lambda_functions();
void test_functions();
void my_functor_adapters();
void my_threads_one();
void my_threads_two();
void set_functions();
void my_strongly_typed_enums();
void my_initializer_list();

// C11 https://habrahabr.ru/post/182920/
// C11 lambda https://habrahabr.ru/post/66021/
// algorithms http://www.cplusplus.com/reference/algorithm/
// Eclipse enable C11 http://stackoverflow.com/questions/17457069/enabling-c11-in-eclipse-juno-kepler-luna-cdt
// Eclipse enable pthread https://stackoverflow.com/questions/4334206/undefined-reference-to-pthread-create-in-c-program-on-eclipse-fedora/8155654
// C11 thread future atomic tasks http://scrutator.me/post/2012/04/04/parallel-world-p1.aspx
// only string has internal function 'find' 'at(i)' '[i]'
// vector has 'at(i)' '[i]'
// list has 'merge' 'remove' 'reverse' 'sort' 'splice'
// map has 'find' 'count' '[key]' 'upper_bound' 'lower_bound' 'equal_range' 'key_comp' 'value_comp'

//int main(int argc, char *argv[])
int main()
{
    try {
        //test_functions();
        input_output_data();
        input_output_data_c();
        string_functions();
        vector_functions();
        list_functions();
        map_auto_functions();
        my_binary_unary_functions();
        my_variadic_templates();
        pointers_functions();
        my_base_derived();
        my_rvalue_lvalue();
        lambda_functions();
        my_functor_adapters();
        my_strongly_typed_enums();
        my_initializer_list();
        my_threads_one();
        my_threads_two();
        set_functions();
        string str("some description.");
        //throw str;
    }
    catch (string &info) {
        cout << "main(): an exception: " << info << endl;
    }
    catch (std::exception &e) {
        cerr << " main(): catch (std::exception &e): " << e.what() << endl;
    }
    catch (...) {
        cerr << "main(): catch (...):" << endl;
    }
    cout << "\n\tmain(): the end of the main().\n";
    return 0;
}
