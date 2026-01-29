1class Solution {
2public:
3    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
4        // Define a large value to represent infinity (no direct path)
5        const int INF = 1 << 29;
6      
7        // Initialize adjacency matrix for 26 letters (a-z)
8        // graph[i][j] represents the minimum cost to change from letter i to letter j
9        int graph[26][26];
10      
11        // Initialize all distances to infinity, except diagonal (same letter) which is 0
12        for (int i = 0; i < 26; ++i) {
13            fill(begin(graph[i]), end(graph[i]), INF);
14            graph[i][i] = 0;  // Cost to change a letter to itself is 0
15        }
16
17        // Build the graph from the given transformations
18        for (int i = 0; i < original.size(); ++i) {
19            int fromChar = original[i] - 'a';  // Convert char to index (0-25)
20            int toChar = changed[i] - 'a';     // Convert char to index (0-25)
21            int transformCost = cost[i];
22          
23            // Keep the minimum cost if there are multiple transformations for the same pair
24            graph[fromChar][toChar] = min(graph[fromChar][toChar], transformCost);
25        }
26
27        // Apply Floyd-Warshall algorithm to find shortest paths between all pairs
28        for (int intermediate = 0; intermediate < 26; ++intermediate) {
29            for (int start = 0; start < 26; ++start) {
30                for (int end = 0; end < 26; ++end) {
31                    // Update shortest path from start to end through intermediate node
32                    graph[start][end] = min(graph[start][end], 
33                                           graph[start][intermediate] + graph[intermediate][end]);
34                }
35            }
36        }
37
38        // Calculate the total minimum cost to transform source string to target string
39        long long totalCost = 0;
40        int stringLength = source.length();
41      
42        for (int i = 0; i < stringLength; ++i) {
43            int sourceChar = source[i] - 'a';  // Convert to index (0-25)
44            int targetChar = target[i] - 'a';  // Convert to index (0-25)
45          
46            // Only need transformation if characters are different
47            if (sourceChar != targetChar) {
48                // Check if transformation is possible
49                if (graph[sourceChar][targetChar] >= INF) {
50                    return -1;  // Impossible to transform this character
51                }
52                totalCost += graph[sourceChar][targetChar];
53            }
54        }
55      
56        return totalCost;
57    }
58};