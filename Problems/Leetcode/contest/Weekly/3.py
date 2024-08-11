from functools import cache
from typing import List


# 好像类似于数位 DP，过不了 T4
class Solution:
    def countOfPairs(self, nums: List[int]) -> int:
        MOD = 1_000_000_007
        n = len(nums)

        @cache
        def dfs(i: int, px: int, py: int) -> int:
            if i >= n:
                return 1

            cnt = 0
            for x in range(px, nums[i] + 1):
                if nums[i] - x > py:
                    continue
                cnt += dfs(i + 1, x, nums[i] - x)
                cnt %= MOD
            return cnt

        res = dfs(0, 0, MOD)
        dfs.cache_clear()
        return res
