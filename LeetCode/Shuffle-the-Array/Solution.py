1class Solution:
2    def shuffle(self, nums: List[int], n: int) -> List[int]:
3        first_half=nums[:n]
4        second_half=nums[n:]
5
6        result=[element for pair in zip(first_half,second_half)for element in pair ]
7        return result
8        