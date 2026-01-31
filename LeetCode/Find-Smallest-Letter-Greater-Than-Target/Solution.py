1class Solution:
2    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
3        """
4        Find the smallest character in letters that is lexicographically greater than target.
5        If no such character exists, return the first character in letters (wrap around).
6
7        Args:
8            letters: A sorted list of characters in non-decreasing order
9            target: The target character to find the next greatest letter for
10
11        Returns:
12            The smallest character greater than target, or the first character if none exists
13        """
14        n = len(letters)
15        left, right = 0, n - 1
16        first_true_index = -1
17
18        # Binary search to find the first index where letters[mid] > target
19        while left <= right:
20            mid = (left + right) // 2
21
22            # Feasible condition: is this character greater than target?
23            if letters[mid] > target:
24                first_true_index = mid  # Record potential answer
25                right = mid - 1  # Search left for smaller valid index
26            else:
27                left = mid + 1  # Search right
28
29        # Handle wrap-around: if no character is greater, return first character
30        if first_true_index == -1:
31            return letters[0]
32        return letters[first_true_index]