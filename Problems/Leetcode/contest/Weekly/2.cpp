#include <bits/stdc++.h>

using namespace std;

#include "D:\Projects\OJ_Code\.headers.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> set(nums.begin(), nums.end());

        ListNode* yummy = new ListNode();
        yummy->next = head;
        ListNode* cur = yummy;
        while (cur->next != nullptr) {
            if (set.contains(cur->next->val)) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }

        ListNode* ans = yummy->next;
        delete yummy;
        return ans;
    }

public:
    ListNode* racing_modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> ump;
        for (int& num : nums) {
            ump[num]++;
        }

        ListNode* yummy = new ListNode();
        yummy->next = head;
        ListNode* cur = yummy;

        vector<int> vec;
        while (head != nullptr) {
            vec.emplace_back(head->val);
            head = head->next;
        }

        for (int& v : vec) {
            if (ump[v]) {
                continue;
            }
            ListNode* node = new ListNode(v);
            cur->next = node;
            cur = node;
        }
        return yummy->next;
    }
};

int main() {
    Solution sol;

    return 0;
}