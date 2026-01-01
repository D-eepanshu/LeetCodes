1from typing import List
2
3class Solution:
4    def plusOne(self, digits: List[int]) -> List[int]:
5        """
6        Adds one to the integer represented by the array of digits.
7      
8        Args:
9            digits: List of integers where each element is a single digit (0-9)
10      
11        Returns:
12            List of integers representing the result of adding one
13        """
14        n = len(digits)
15      
16        # Iterate through digits from right to left (least significant to most significant)
17        for i in range(n - 1, -1, -1):
18            # Add 1 to the current digit
19            digits[i] += 1
20          
21            # Handle carry by taking modulo 10
22            digits[i] %= 10
23          
24            # If the digit is not 0, there's no carry, so we can return
25            if digits[i] != 0:
26                return digits
27      
28        # If we reach here, all digits were 9 (e.g., 999 -> 1000)
29        # Need to add a leading 1
30        return [1] + digits