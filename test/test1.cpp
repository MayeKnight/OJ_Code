#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

auto print_seq = [](auto rem, auto first, auto last) {
    for (std::cout << rem; first != last; std::cout << *first++ << ' ') {}
    std::cout << '\n';
};

int main() {
    std::array v {1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto is_even = [](int i) {
        return i % 2 == 0;
    };

    std::partition(v.begin(), v.end(), is_even);
    print_seq("划分后: ", v.cbegin(), v.cend());

    const auto pp = std::partition_point(v.cbegin(), v.cend(), is_even);
    const auto i = std::distance(v.cbegin(), pp);
    std::cout << "划分点在 " << i << "; v[" << i << "] = " << *pp << '\n';

    print_seq("第一分段（所有偶数元素）：", v.cbegin(), pp);
    print_seq("第二分段（所有奇数元素）：", pp, v.cend());
}