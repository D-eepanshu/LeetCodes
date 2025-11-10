def minOperations(self, nums: List[int]) -> int:
    s = [-1]
    res = 0
    for a in nums:
        while s[-1] > a:
            s.pop()
        if a == 0:
            continue
        if s[-1] < a:
            res += 1
            s.append(a)
    return res