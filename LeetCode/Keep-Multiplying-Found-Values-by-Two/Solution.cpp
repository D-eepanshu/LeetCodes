def findFinalValue(self, nums: list[int], k: int) -> int:
    bits = 0                              # used as a set
    for num in nums:
        q, r = divmod(num, k)             # q = normalized num
        if r == 0 and (q & (q - 1)) == 0: # check power of 2
            bits |= q                     # store power of 2
    n = ~bits                             # flip bits
    return k * (n & -n)                   # find missing power * k
