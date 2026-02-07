1class Solution:
2    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
3        """
4        Find the minimum cost by selecting k elements where the first element is always included,
5        and subsequent elements must be within 'dist' distance from each other.
6      
7        Args:
8            nums: List of numbers to select from
9            k: Number of elements to select
10            dist: Maximum distance constraint between consecutive selected elements
11      
12        Returns:
13            Minimum sum of k selected elements
14        """
15        from sortedcontainers import SortedList
16      
17        # Helper function to move the largest element from left set to right set
18        def move_from_left_to_right():
19            nonlocal current_sum
20            element = left_set.pop()  # Remove largest element from left set
21            current_sum -= element
22            right_set.add(element)
23      
24        # Helper function to move the smallest element from right set to left set
25        def move_from_right_to_left():
26            nonlocal current_sum
27            element = right_set.pop(0)  # Remove smallest element from right set
28            left_set.add(element)
29            current_sum += element
30      
31        # Adjust k since the first element is always included
32        k -= 1
33      
34        # Initialize with the first window (elements from index 1 to dist+1)
35        # nums[0] is always included, so we start the window from index 1
36        current_sum = sum(nums[:dist + 2])  # Sum including nums[0]
37        left_set = SortedList(nums[1:dist + 2])  # Window elements (excluding nums[0])
38        right_set = SortedList()  # Elements outside the k smallest in current window
39      
40        # Ensure left_set contains exactly k elements (the k smallest in window)
41        while len(left_set) > k:
42            move_from_left_to_right()
43      
44        # Initialize answer with the first window's sum
45        min_cost = current_sum
46      
47        # Slide the window through the rest of the array
48        for i in range(dist + 2, len(nums)):
49            # Remove the element that's going out of the window
50            outgoing_element = nums[i - dist - 1]
51            if outgoing_element in left_set:
52                left_set.remove(outgoing_element)
53                current_sum -= outgoing_element
54            else:
55                right_set.remove(outgoing_element)
56          
57            # Add the new element entering the window
58            incoming_element = nums[i]
59            if left_set and incoming_element < left_set[-1]:
60                # If new element is smaller than largest in left_set, add to left_set
61                left_set.add(incoming_element)
62                current_sum += incoming_element
63            else:
64                # Otherwise, add to right_set
65                right_set.add(incoming_element)
66          
67            # Rebalance to ensure left_set has exactly k elements
68            while len(left_set) < k:
69                move_from_right_to_left()
70            while len(left_set) > k:
71                move_from_left_to_right()
72          
73            # Update the minimum cost
74            min_cost = min(min_cost, current_sum)
75      
76        return min_cost