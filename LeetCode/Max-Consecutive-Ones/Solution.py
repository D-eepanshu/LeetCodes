1class Solution:
2    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
3        """
4        Find the maximum number of consecutive 1s in a binary array.
5      
6        Args:
7            nums: List of binary integers (0s and 1s)
8          
9        Returns:
10            Maximum length of consecutive 1s
11        """
12        max_consecutive = 0  # Track the maximum consecutive 1s found so far
13        current_consecutive = 0  # Track the current consecutive 1s count
14      
15        # Iterate through each number in the array
16        for num in nums:
17            if num == 1:
18                # If current number is 1, increment the consecutive counter
19                current_consecutive += 1
20                # Update maximum if current consecutive count is larger
21                max_consecutive = max(max_consecutive, current_consecutive)
22            else:
23                # If current number is 0, reset the consecutive counter
24                current_consecutive = 0
25      
26        return max_consecutive