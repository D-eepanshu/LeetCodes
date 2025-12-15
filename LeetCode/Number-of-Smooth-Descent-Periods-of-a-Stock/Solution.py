1from typing import List
2
3class Solution:
4    def getDescentPeriods(self, prices: List[int]) -> int:
5        """
6        Count the total number of smooth descent periods in the prices array.
7        A smooth descent period is a subarray where each element is exactly 1 less than the previous.
8      
9        Args:
10            prices: List of integers representing prices
11          
12        Returns:
13            Total count of all smooth descent periods (including single elements)
14        """
15        total_periods = 0
16        current_index = 0
17        array_length = len(prices)
18      
19        # Process the array by finding consecutive descent sequences
20        while current_index < array_length:
21            # Find the end of current descent sequence
22            next_index = current_index + 1
23          
24            # Extend the sequence while the descent condition is met
25            # (previous element minus current element equals 1)
26            while next_index < array_length and prices[next_index - 1] - prices[next_index] == 1:
27                next_index += 1
28          
29            # Calculate the length of the current descent sequence
30            sequence_length = next_index - current_index
31          
32            # Add the number of subarrays in this sequence
33            # For a sequence of length n, there are n*(n+1)/2 subarrays
34            total_periods += (1 + sequence_length) * sequence_length // 2
35          
36            # Move to the next unprocessed element
37            current_index = next_index
38      
39        return total_periods
40