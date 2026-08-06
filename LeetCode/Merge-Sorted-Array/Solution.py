1class Solution:
2    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
3        """
4        Do not return anything, modify nums1 in-place instead.
5        """
6        #del nums1[m:]
7        for i in range(n):
8            del nums1[m]
9        nums1.extend(nums2)
10        nums1.sort()
11        return nums1       
12        