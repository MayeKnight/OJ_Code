#include <algorithm>
#include <array>
#include <complex>
#include <iostream>
#include <ranges>
#include <set>
#include <vector>

constexpr int N = 1024;

auto print_seq = [](auto rem, auto first, auto last) {
    for (std::cout << rem; first != last; std::cout << *first++ << ' ') {}
    std::cout << '\n';
};

/*
    bitset<>  bit_width

    foreach

    iota

    replace

    accumulate  reduce

    format

    prev  next
    prev_permutation  next_permutation

    is_sorted

    > ranges::
    minmax  equal_range
*/

int main() {
    std::complex<float> z = 4.0 + 3i;
    std::cout << std::real(z) << " " << std::imag(z) << " " << std::conj(z) << "\n";

    std::string str = "abasfnas";
    std::set<char> set(str.begin(), str.end());
    std::vector<char> tmp {'s', 'a', 'b'};
    std::cout << std::boolalpha << std::ranges::includes(str, tmp) << "\n";

    for (const int& i : std::ranges::iota_view(1) | std::ranges::views::take(10)) {
        std::printf("%d ", i);
    }
    std::cout << "\n";

    std::cout << std::__lg(N) << "\n";

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

    // std::cout << __cplusplus << "\n";

    return 0;
}