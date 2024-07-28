from typing import List


class Solution:
    def canAliceWin(self, nums: List[int]) -> bool:
        c1 = 0
        c2 = 0
        for v in nums:
            if len(str(v)) == 1:
                c1 += v
            else:
                c2 += v
        return c1 != c2
