1class Solution:
2    def isPalindrome(self, x: int) -> bool:
3       new = str(x)
4       return new == new[::-1]
5