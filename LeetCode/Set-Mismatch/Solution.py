1from typing import List
2
3class Solution:
4    def findErrorNums(self, nums: List[int]) -> List[int]:
5        """
6        Find the duplicate number and the missing number in an array.
7      
8        The array should contain numbers from 1 to n, but one number appears twice
9        and another number is missing.
10      
11        Args:
12            nums: List of integers from 1 to n with one duplicate and one missing
13          
14        Returns:
15            List containing [duplicate_number, missing_number]
16        """
17        n = len(nums)
18      
19        # Calculate the expected sum of numbers from 1 to n using arithmetic series formula
20        expected_sum = (1 + n) * n // 2
21      
22        # Calculate the sum of unique numbers in the array (removes the duplicate)
23        unique_sum = sum(set(nums))
24      
25        # Calculate the actual sum of all numbers in the array (includes the duplicate)
26        actual_sum = sum(nums)
27      
28        # The duplicate number = actual_sum - unique_sum
29        duplicate_number = actual_sum - unique_sum
30      
31        # The missing number = expected_sum - unique_sum
32        missing_number = expected_sum - unique_sum
33      
34        return [duplicate_number, missing_number]