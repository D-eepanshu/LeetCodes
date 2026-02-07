1class Solution:
2    def minimumDeletions(self, s: str) -> int:
3        # Get the length of the input string
4        n = len(s)
5      
6        # dp[i] represents minimum deletions needed to make s[0:i] balanced
7        # We use n+1 size to handle 1-indexed iteration
8        dp = [0] * (n + 1)
9      
10        # Count of 'b' characters seen so far
11        b_count = 0
12      
13        # Iterate through each character with 1-based indexing
14        for i, char in enumerate(s, 1):
15            if char == 'b':
16                # If current character is 'b', no additional deletion needed
17                # The string remains balanced up to this point
18                dp[i] = dp[i - 1]
19                b_count += 1
20            else:
21                # If current character is 'a', we have two choices:
22                # 1. Delete this 'a' (cost: dp[i-1] + 1)
23                # 2. Keep this 'a' and delete all previous 'b's (cost: b_count)
24                dp[i] = min(dp[i - 1] + 1, b_count)
25      
26        # Return the minimum deletions needed for the entire string
27        return dp[n]
28
29