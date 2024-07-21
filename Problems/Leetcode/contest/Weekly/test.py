from typing import List


class Solution:
    def minimumOperations(self, nums: List[int], target: List[int]) -> int:
        lst = [map(lambda x, y: x - y, target, nums)]
        print(lst)
        return 0
