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

int main() {
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

    // std::cout << __cplusplus << "\n";
    return 0;
}