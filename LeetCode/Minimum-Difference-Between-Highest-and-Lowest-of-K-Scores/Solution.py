1class Solution:
2    def minimumDifference(self, nums: List[int], k: int) -> int:
3        # Sort the array in ascending order to group similar values together
4        nums.sort()
5      
6        # Find the minimum difference between max and min in any window of size k
7        # We iterate through all possible windows of size k
8        # For each window starting at index i, the difference is nums[i+k-1] - nums[i]
9        return min(nums[i + k - 1] - nums[i] for i in range(len(nums) - k + 1))
10