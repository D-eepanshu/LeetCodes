1class Solution:
2    def bestClosingTime(self, customers: str) -> int:
3        """
4        Find the best hour to close the shop to minimize penalty.
5        Penalty = number of 'N' hours before closing + number of 'Y' hours after closing
6      
7        Args:
8            customers: String of 'Y' (customer arrives) or 'N' (no customer) for each hour
9          
10        Returns:
11            The optimal closing hour (0 to n inclusive)
12        """
13        n = len(customers)
14      
15        # Build prefix sum array for counting 'Y's
16        # prefix_sum[i] = number of 'Y's in customers[0:i]
17        prefix_sum = [0] * (n + 1)
18        for i, customer in enumerate(customers):
19            prefix_sum[i + 1] = prefix_sum[i] + (1 if customer == 'Y' else 0)
20      
21        # Find the closing hour with minimum penalty
22        best_hour = 0
23        min_penalty = float('inf')
24      
25        for closing_hour in range(n + 1):
26            # Calculate penalty for closing at this hour
27            # Penalty before closing: number of 'N's from hour 0 to closing_hour-1
28            # = closing_hour - number of 'Y's before closing_hour
29            penalty_before = closing_hour - prefix_sum[closing_hour]
30          
31            # Penalty after closing: number of 'Y's from closing_hour to end
32            # = total 'Y's - 'Y's before closing_hour
33            penalty_after = prefix_sum[-1] - prefix_sum[closing_hour]
34          
35            total_penalty = penalty_before + penalty_after
36          
37            # Update best closing hour if we found a lower penalty
38            if total_penalty < min_penalty:
39                best_hour = closing_hour
40                min_penalty = total_penalty
41      
42        return best_hour