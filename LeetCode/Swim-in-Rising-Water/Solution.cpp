class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // Min-heap: (max elevation on path so far, row, col)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        // 4-directional movement (up, right, down, left)
        vector<int> dir = {-1, 0, 1, 0, -1};

        while (!pq.empty()) {
            auto [time, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == n - 1) {
                return time; // Reached destination
            }

            for (int i = 0; i < 4; ++i) {
                int nr = r + dir[i];
                int nc = c + dir[i + 1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({max(time, grid[nr][nc]), nr, nc});
                }
            }
        }

        return -1; // Should never reach here
    }
};
