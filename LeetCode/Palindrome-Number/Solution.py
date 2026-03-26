1class Solution:
2    def isPalindrome(self, x: int) -> bool:
3       new = str(x)
4       check = new[::-1]
5       if check == new:
6            return True
7       else:
8            return False
9