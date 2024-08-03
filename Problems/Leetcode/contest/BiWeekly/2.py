from typing import List

fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y
MOD = 1_000_000_007


class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        return fmin(
            sum(
                1
                for i in range(n)
                for j in range(m // 2)
                if grid[i][j] != grid[i][m - 1 - j]
            ),
            sum(
                1
                for j in range(m)
                for i in range(n // 2)
                if grid[i][j] != grid[n - 1 - i][j]
            ),
        )
