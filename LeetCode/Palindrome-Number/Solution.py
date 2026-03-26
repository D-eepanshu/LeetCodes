1class Solution:
2    def isPalindrome(self, x: int) -> bool:
3        s = str(x)
4        left, right = 0, len(s) - 1
5        
6        while left < right:
7            if s[left] != s[right]:
8                return False
9            left += 1
10            right -= 1
11        
12        return True