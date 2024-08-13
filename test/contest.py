if 1:
    from collections import defaultdict, deque
    from functools import cache
    from typing import List
    from sortedcontainers import SortedList

    fmax = lambda x, y: x if x > y else y
    fmin = lambda x, y: x if x < y else y

    MOD = 1_000_000_007
