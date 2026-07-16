1class Solution:
2    def reverse(self, x: int) -> int:
3        rev = int(str(abs(x))[::-1])
4        if rev<-2**31 or rev>2**31 -1:
5            return 0
6        else:
7            return -rev if x<0 else rev
8        