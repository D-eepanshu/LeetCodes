1from typing import List
2from math import inf
3
4class Solution:
5    def minimumCost(self, nums: List[int]) -> int:
6        # First element is fixed as the first part of our sum
7        first_element = nums[0]
8      
9        # Initialize two variables to track the two smallest elements from index 1 onwards
10        # smallest: the minimum element found so far
11        # second_smallest: the second minimum element found so far
12        smallest = inf
13        second_smallest = inf
14      
15        # Iterate through all elements starting from index 1
16        for current_num in nums[1:]:
17            if current_num < smallest:
18                # If current number is smaller than the smallest,
19                # update both: previous smallest becomes second smallest
20                second_smallest = smallest
21                smallest = current_num
22            elif current_num < second_smallest:
23                # If current number is between smallest and second smallest,
24                # only update second smallest
25                second_smallest = current_num
26      
27        # Return sum of first element and two smallest elements from the rest
28        return first_element + smallest + second_smallest