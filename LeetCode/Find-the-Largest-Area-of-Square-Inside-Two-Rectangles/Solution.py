1from typing import List
2from itertools import combinations
3
4
5class Solution:
6    def largestSquareArea(
7        self, bottomLeft: List[List[int]], topRight: List[List[int]]
8    ) -> int:
9        """
10        Find the largest square area that can be formed from the intersection of rectangles.
11      
12        Args:
13            bottomLeft: List of [x, y] coordinates representing bottom-left corners of rectangles
14            topRight: List of [x, y] coordinates representing top-right corners of rectangles
15          
16        Returns:
17            The area of the largest square that can be formed from rectangle intersections
18        """
19        max_square_area = 0
20      
21        # Iterate through all pairs of rectangles
22        for ((x1, y1), (x2, y2)), ((x3, y3), (x4, y4)) in combinations(
23            zip(bottomLeft, topRight), 2
24        ):
25            # Calculate the intersection rectangle dimensions
26            # Width of intersection: rightmost left edge to leftmost right edge
27            intersection_width = min(x2, x4) - max(x1, x3)
28          
29            # Height of intersection: topmost bottom edge to bottommost top edge  
30            intersection_height = min(y2, y4) - max(y1, y3)
31          
32            # The maximum square side length is limited by the smaller dimension
33            max_square_side = min(intersection_width, intersection_height)
34          
35            # Only consider valid intersections (positive dimensions)
36            if max_square_side > 0:
37                square_area = max_square_side * max_square_side
38                max_square_area = max(max_square_area, square_area)
39              
40        return max_square_area
41