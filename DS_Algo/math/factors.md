```cpp []
#define N 100000

vector<vector<int>> factors(N);
for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
        factors[j].emplace_back(i);
    }
}
```