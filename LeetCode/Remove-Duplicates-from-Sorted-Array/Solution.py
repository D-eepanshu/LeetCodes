1from collections import Counter
2class Solution:
3
4    def removeDuplicates(self, nums: List[int]) -> int:
5        if not nums:
6            return 0
7        k=1
8        for i in range(1,len(nums)):
9            if nums[i] != nums[k-1]:
10                nums[k] =nums[i]
11                k+=1
12        return k