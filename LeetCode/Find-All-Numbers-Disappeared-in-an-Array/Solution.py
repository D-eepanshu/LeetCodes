1class Solution:
2    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
3        """
4        Find all numbers in range [1, n] that don't appear in the array.
5      
6        Args:
7            nums: List of integers where n is the length of the array
8      
9        Returns:
10            List of integers that are missing from the range [1, n]
11        """
12        # Convert the input list to a set for O(1) lookup time
13        numbers_present = set(nums)
14      
15        # Build result list by checking each number in range [1, n]
16        # If a number is not in the set, it's missing from the original array
17        missing_numbers = [
18            number 
19            for number in range(1, len(nums) + 1) 
20            if number not in numbers_present
21        ]
22      
23        return missing_numbers