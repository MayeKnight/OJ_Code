1. `前后缀`
```cpp
vector<int> pre(n + 1);
for (int i = 0; i < n; ++i) {
    pre[i + 1] = pre[i] + vec[i];
}

vector<int> suf(n + 1);
for (int i = n - 1; i >= 0; --i) {
    suf[i] = suf[i + 1] + vec[i];
}
```

2. `字典树 trie`
```cpp
struct Node {
    Node* son[26] {};

    // something else
};

Node* root = new Node();

// process
    Node* cur = root;
```
