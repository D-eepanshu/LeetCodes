1class Solution:
2    def addBinary(self, a: str, b: str) -> str:
3        """
4        Add two binary strings and return their sum as a binary string.
5      
6        Args:
7            a: First binary number as string (e.g., "1010")
8            b: Second binary number as string (e.g., "101")
9          
10        Returns:
11            Sum of the two binary numbers as a binary string
12        """
13        # Convert binary string 'a' to integer (base 2)
14        decimal_a = int(a, 2)
15      
16        # Convert binary string 'b' to integer (base 2)
17        decimal_b = int(b, 2)
18      
19        # Add the two decimal numbers
20        decimal_sum = decimal_a + decimal_b
21      
22        # Convert the sum back to binary string
23        # bin() returns format like '0b101', so we slice from index 2
24        binary_result = bin(decimal_sum)[2:]
25      
26        return binary_result