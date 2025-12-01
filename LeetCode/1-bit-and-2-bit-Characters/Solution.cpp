1class Solution {
2public:
3    bool isOneBitCharacter(vector<int>& bits) {
4        // Initialize pointer and get array size
5        int i = 0;
6        int n = bits.size();
7      
8        // Traverse through the bits array until we reach or pass the second-to-last position
9        // If current bit is 0: it's a 1-bit character, move forward by 1 (0 + 1)
10        // If current bit is 1: it's a 2-bit character, move forward by 2 (1 + 1)
11        while (i < n - 1) {
12            i += bits[i] + 1;
13        }
14      
15        // If we landed exactly on the last position (n-1), 
16        // it means the last character is a 1-bit character
17        return i == n - 1;
18    }
19};
20