#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <iterator>

using namespace std;

//

void my_common_set_functions();

void set_functions() {
    //my_common_set_functions();
}

void my_common_set_functions() {
    unordered_set<int> data_set = {1, 3, 5, 7, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    //for (int i = 30; i < 90000; i++)
    //    data_set.insert(i);

    copy(data_set.cbegin(), data_set.cend(), ostream_iterator<int>(cout, ":"));
    cout << endl;
    for(const auto &element : data_set) {
        cout << element << "-";
    }
    cout << endl;
    cout << "bucket_count: " << data_set.bucket_count() << endl;
    cout << "max_bucket_count: 0x" << std::hex << data_set.max_bucket_count() << endl;

    cout << std::dec << "load factor: " << data_set.load_factor() << endl;
    cout << std::dec << "max load factor: " << data_set.max_load_factor() << endl;
    int x = 10;
    cout << "bucket: " << data_set.bucket(x) << endl;

    cout << "bucket_size:\n";
    for (int i = 0; i < data_set.bucket_count(); i++) {
        cout << "data_set(" << i << "): " << data_set.bucket_size(i) << endl;
    }
    cout << "\n" << "bucket(2):\n";
    auto it_bucket_1_begin = data_set.begin(1);
    auto it_bucket_1_end = data_set.end(1);
    cout << "element:" << *it_bucket_1_begin << "\n";
    it_bucket_1_begin++;
    cout << "element:" << *it_bucket_1_begin << "\n";
    it_bucket_1_begin++;
    if (it_bucket_1_begin == it_bucket_1_end)
        cout << "the end in this bucket\n";

}
