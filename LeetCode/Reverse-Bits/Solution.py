1class Solution:
2    def reverseBits(self, n: int) -> int:
3        """
4        Reverse the bits of a 32-bit unsigned integer.
5      
6        Args:
7            n: A 32-bit unsigned integer to reverse
8          
9        Returns:
10            The integer with bits reversed
11        """
12        result = 0
13      
14        # Process all 32 bits
15        for i in range(32):
16            # Extract the least significant bit from n using AND operation
17            # Shift it to its reversed position (31-i) and add to result using OR
18            result |= (n & 1) << (31 - i)
19          
20            # Right shift n by 1 to process the next bit in the next iteration
21            n >>= 1
22          
23        return result