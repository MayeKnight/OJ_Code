单调（双端）队列：
    移除最左边的元素，
    移除最右边的元素，
    在最右边插入元素，
    从队首到队尾单调。

    存放下标，以便根据窗口大小弹出队首元素。

三步走：
    入（保证有序）
    出（队首离开窗口）
    记录答案

```cpp
// https://leetcode.cn/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.emplace_back(i);
            if (i - q.front() + 1 > k) {
                q.pop_front();
            }
            if (i >= k - 1) {
                ans.emplace_back(nums[q.front()]);
            }
        }
        return ans;
    }
};
```

