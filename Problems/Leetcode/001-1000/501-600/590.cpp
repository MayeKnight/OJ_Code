#include <bits/stdc++.h>

#include "D:\Projects\Code\.headers.hpp"

using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> postorder_0(Node* root) {
        vector<int> ans;

        function<void(Node*)> dfs = [&](Node* root) -> void {
            if (root == nullptr) {
                return;
            }

            for (const auto& node : root->children) {
                dfs(node);
            }

            ans.emplace_back(root->val);
        };

        dfs(root);

        return ans;
    }

public:
    vector<int> postorder_1(Node* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        unordered_map<Node*, int> cnt;
        stack<Node*> st;
        Node* node = root;
        while (!st.empty() || node != nullptr) {
            while (node != nullptr) {
                st.emplace(node);
                if (node->children.size() > 0) {
                    cnt[node] = 0;
                    node = node->children[0];
                } else {
                    node = nullptr;
                }
            }
            node = st.top();
            int index = cnt.count(node) ? (cnt[node] + 1) : 0;
            if (index < node->children.size()) {
                cnt[node] = index;
                node = node->children[index];
            } else {
                res.emplace_back(node->val);
                st.pop();
                cnt.erase(node);
                node = nullptr;
            }
        }
        return res;
    }

public:
    vector<int> postorder_2(Node* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<Node*> st;
        unordered_set<Node*> visited;
        st.emplace(root);
        while (!st.empty()) {
            Node* node = st.top();
            /* 如果当前节点为叶子节点或者当前节点的子节点已经遍历过 */
            if (node->children.size() == 0 || visited.count(node)) {
                res.emplace_back(node->val);
                st.pop();
                continue;
            }
            for (auto it = node->children.rbegin(); it != node->children.rend(); it++) {
                st.emplace(*it);
            }
            visited.emplace(node);
        }
        return res;
    }
};