1class Solution:
2    def countNegatives(self, grid: List[List[int]]) -> int:
3        """
4        Count the number of negative numbers in a sorted matrix.
5        Uses binary search on each row to find the first negative.
6
7        Time Complexity: O(m log n) where m is rows and n is columns
8        Space Complexity: O(1)
9        """
10        rows, cols = len(grid), len(grid[0])
11        total_count = 0
12
13        # Apply binary search on each row
14        for row in range(rows):
15            # Binary search template: find first negative (first true)
16            left, right = 0, cols - 1
17            first_true_index = -1
18
19            while left <= right:
20                mid = (left + right) // 2
21                # Feasible condition: is this element negative?
22                if grid[row][mid] < 0:
23                    first_true_index = mid
24                    right = mid - 1  # Search left for earlier negative
25                else:
26                    left = mid + 1  # Search right for negatives
27
28            # If we found a negative, count all elements from that index to end
29            if first_true_index != -1:
30                total_count += cols - first_true_index
31
32        return total_count