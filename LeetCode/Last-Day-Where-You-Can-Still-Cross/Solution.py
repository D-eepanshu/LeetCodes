1class Solution:
2    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
3        def can_cross(day: int) -> bool:
4            """Check if it's possible to cross from top to bottom on the given day."""
5            grid = [[0] * col for _ in range(row)]
6
7            for i in range(day):
8                r, c = cells[i]
9                grid[r - 1][c - 1] = 1
10
11            queue = []
12            for j in range(col):
13                if grid[0][j] == 0:
14                    queue.append((0, j))
15                    grid[0][j] = 1
16
17            idx = 0
18            while idx < len(queue):
19                x, y = queue[idx]
20                idx += 1
21
22                if x == row - 1:
23                    return True
24
25                for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
26                    next_x, next_y = x + dx, y + dy
27                    if 0 <= next_x < row and 0 <= next_y < col and grid[next_x][next_y] == 0:
28                        queue.append((next_x, next_y))
29                        grid[next_x][next_y] = 1
30
31            return False
32
33        def feasible(day: int) -> bool:
34            """Returns true when crossing is NOT possible (inverted condition)."""
35            return not can_cross(day)
36
37        # Binary search for first day where crossing becomes impossible
38        left, right = 1, len(cells)
39        first_true_index = -1
40
41        while left <= right:
42            mid = (left + right) // 2
43            if feasible(mid):
44                first_true_index = mid
45                right = mid - 1
46            else:
47                left = mid + 1
48
49        # Return the last day where crossing was still possible
50        return first_true_index - 1