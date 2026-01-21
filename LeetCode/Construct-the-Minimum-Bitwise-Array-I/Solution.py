1class Solution:
2    def minBitwiseArray(self, nums: List[int]) -> List[int]:
3        """
4        For each number in nums, find the minimum value ans[i] such that
5        ans[i] OR (ans[i] + 1) = nums[i], or -1 if no such value exists.
6      
7        Args:
8            nums: List of integers to process
9          
10        Returns:
11            List of minimum values or -1 for each number in nums
12        """
13        result = []
14      
15        for num in nums:
16            # Special case: 2 has no valid answer
17            # Because 2 in binary is 10, and no value OR (value+1) can produce this
18            if num == 2:
19                result.append(-1)
20            else:
21                # Find the rightmost 0 bit in num (searching from bit position 1)
22                for bit_position in range(1, 32):
23                    # Check if the bit at current position is 0
24                    if ((num >> bit_position) & 1) == 0:
25                        # Found the rightmost 0 bit
26                        # XOR with 1 shifted to the previous bit position
27                        # This effectively clears the bit before the found 0
28                        answer = num ^ (1 << (bit_position - 1))
29                        result.append(answer)
30                        break
31      
32        return result