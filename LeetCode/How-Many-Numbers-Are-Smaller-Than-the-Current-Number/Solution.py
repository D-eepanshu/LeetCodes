1from typing import List
2from bisect import bisect_left
3
4class Solution:
5    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
6        # Create a sorted copy of the input array
7        # This allows us to use binary search to find positions
8        sorted_nums = sorted(nums)
9      
10        # For each number in the original array, find how many numbers are smaller
11        # bisect_left returns the leftmost position where the number would be inserted
12        # This position equals the count of numbers smaller than the current number
13        result = [bisect_left(sorted_nums, num) for num in nums]
14      
15        return result
16