#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
#include <format>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

constexpr int N = 1024;

auto print_seq = [](auto rem, auto first, auto last) {
    for (std::cout << rem; first != last; std::cout << *first++ << ' ') {}
    std::cout << '\n';
};

int main() {
    std::vector<int> vec {1, 2, 4};
    std::cout << std::boolalpha << is_sorted(vec.begin(), vec.end()) << "\n";

    std::bitset<5> bits(5);
    for (int i = 0; i < 5; ++i) {
        std::cout << bits.test(i) << "\n";
    }

    std::complex<float> z = 4.0 + 3i;
    std::cout << std::real(z) << " " << std::imag(z) << " " << std::conj(z) << "\n";

    std::string str = "abasfnas";
    std::set<char> set(str.begin(), str.end());
    for_each(set.begin(), set.end(), [&](char ch) { std::cout << ch << " "; });
    std::vector<char> tmp {'s', 'a', 'b'};
    std::cout << std::boolalpha << std::ranges::includes(str, tmp) << "\n";
    std::cout << std::boolalpha << std::is_sorted(str.begin(), str.end()) << "\n";

    std::array arr = std::to_array({0, 3, 2, 1, 1, 2});
    auto [mn, mx] = std::ranges::minmax(arr);
    std::cout << std::format("min = {}, max = {}\n", mn, mx);
    std::cout << std::accumulate(arr.begin(), arr.end(), 0) << "\n";
    std::cout << std::reduce(arr.begin(), arr.end()) << "\n";
    std::ranges::sort(arr);
    auto [l_iter, r_iter] = std::ranges::equal_range(arr, 1);
    std::cout << *std::prev(l_iter) << "\n";

    for (const int& i : std::ranges::iota_view(1) | std::ranges::views::take(10)) {
        std::printf("%d ", i);
    }
    std::cout << "\n";

    std::cout << std::__lg(N) << "\n";

    std::string s("dbca");
    do {
        for (auto& v : s) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    } while (prev_permutation(s.begin(), s.end())); // next_permutation

    std::vector<int> nums(50);
    std::iota(nums.begin(), nums.end(), 0);
    std::ranges::partition(nums, [](int i) { return i % 2 == 0; });
    for (int& v : nums) {
        std::cout << v << " ";
    }
    std::cout << "\n";

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