#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt range_begin, RandomIt range_end,
        char prefix) {
     string pref_str = {prefix};
    auto low = lower_bound(range_begin, range_end, pref_str);
    char next_letter = static_cast<char>(prefix + 1);
    string next_let_str = {next_letter};
    auto up = lower_bound(range_begin, range_end, next_let_str);
    return {low, up};
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt range_begin, RandomIt range_end,
        const string& prefix) {

    auto low = lower_bound(range_begin, range_end, prefix);
    char next_letter = static_cast<char>(prefix[prefix.size()-1] + 1);
    string next_let_str = prefix;
    next_let_str[prefix.size()-1] = next_letter;
    auto up = lower_bound(range_begin, range_end, next_let_str);
    return {low, up};
}

int main() {
    const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

    const auto mo_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto mt_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    cout << (mt_result.first - begin(sorted_strings)) << " " <<
         (mt_result.second - begin(sorted_strings)) << endl;

    const auto na_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    cout << (na_result.first - begin(sorted_strings)) << " " <<
         (na_result.second - begin(sorted_strings)) << endl;

    return 0;
}