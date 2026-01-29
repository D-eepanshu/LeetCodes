1class Solution {
2public:
3    int minCost(vector<vector<int>>& grid, int k) {
4        int m = grid.size(), n = grid[0].size();
5        int inf = INT_MAX / 2;
6
7        vector<vector<vector<int>>> f(k + 1, vector<vector<int>>(m, vector<int>(n, inf)));
8
9        f[0][0][0] = 0;
10        for (int i = 0; i < m; i++) {
11            for (int j = 0; j < n; j++) {
12                if (i > 0) {
13                    f[0][i][j] = min(f[0][i][j], f[0][i - 1][j] + grid[i][j]);
14                }
15                if (j > 0) {
16                    f[0][i][j] = min(f[0][i][j], f[0][i][j - 1] + grid[i][j]);
17                }
18            }
19        }
20
21        unordered_map<int, vector<pair<int, int>>> g;
22        for (int i = 0; i < m; i++) {
23            for (int j = 0; j < n; j++) {
24                int x = grid[i][j];
25                g[x].push_back({i, j});
26            }
27        }
28
29        vector<int> keys;
30        keys.reserve(g.size());
31        for (auto& e : g) {
32            keys.push_back(e.first);
33        }
34        sort(keys.begin(), keys.end(), greater<int>());
35
36        for (int t = 1; t <= k; t++) {
37            int mn = inf;
38            for (int key : keys) {
39                auto& pos = g[key];
40                for (auto& p : pos) {
41                    mn = min(mn, f[t - 1][p.first][p.second]);
42                }
43                for (auto& p : pos) {
44                    f[t][p.first][p.second] = mn;
45                }
46            }
47            for (int i = 0; i < m; i++) {
48                for (int j = 0; j < n; j++) {
49                    if (i > 0) {
50                        f[t][i][j] = min(f[t][i][j], f[t][i - 1][j] + grid[i][j]);
51                    }
52                    if (j > 0) {
53                        f[t][i][j] = min(f[t][i][j], f[t][i][j - 1] + grid[i][j]);
54                    }
55                }
56            }
57        }
58
59        int ans = inf;
60        for (int t = 0; t <= k; t++) {
61            ans = min(ans, f[t][m - 1][n - 1]);
62        }
63        return ans;
64    }
65};