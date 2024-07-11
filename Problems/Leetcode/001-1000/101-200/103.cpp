#include <bits/stdc++.h>

#include "D:\Projects\Code\.headers.hpp"

using namespace std;
using ll = long long;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //* 反转
        // vector<vector<int>> ans;
        // queue<TreeNode*> q;
        // if (root == nullptr) {
        //     return ans;
        // }

        // int k = 0;
        // q.emplace(root);
        // while (!q.empty()) {
        //     int cnt = q.size();
        //     vector<int> temp;
        //     while (cnt--) {
        //         TreeNode* node = q.front();
        //         q.pop();

        //         if (node->left) {
        //             q.emplace(node->left);
        //         }
        //         if (node->right) {
        //             q.emplace(node->right);
        //         }

        //         temp.emplace_back(node->val);
        //     }

        //     if (k & 1) {
        //         ranges::reverse(temp);
        //     }
        //     ans.emplace_back(temp);
        //     k ^= 1;
        // }

        // return ans;

        //* 双端队列
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }

        deque<TreeNode*> dq;
        dq.emplace_back(root);
        bool flag = true;
        while (!dq.empty()) {
            int cnt = dq.size();
            ans.emplace_back(vector<int>());

            TreeNode* node;
            while (cnt--) {
                if (flag) { // 踢前面，放后面
                    node = dq.front();
                    dq.pop_front();

                    if (node->left) {
                        dq.emplace_back(node->left);
                    }
                    if (node->right) {
                        dq.emplace_back(node->right);
                    }
                } else { // 踢后面，放前面
                    node = dq.back();
                    dq.pop_back();

                    if (node->right) {
                        dq.emplace_front(node->right);
                    }
                    if (node->left) {
                        dq.emplace_front(node->left);
                    }
                }

                ans.back().emplace_back(node->val);
            }

            flag = !flag;
        }

        return ans;
    }
};