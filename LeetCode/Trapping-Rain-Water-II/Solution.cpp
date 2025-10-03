class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m <= 2 || n <= 2) return 0;

        // Min-heap based on cell height
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Push all boundary cells
        for (int i = 0; i < m; ++i) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; ++j) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});
            visited[0][j] = true;
            visited[m - 1][j] = true;
        }

        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int trapped = 0;

        while (!pq.empty()) {
            auto cell = pq.top(); pq.pop();
            int height = cell[0], x = cell[1], y = cell[2];

            for (auto& dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny])
                    continue;

                visited[nx][ny] = true;

                // Water trapped at this neighbor
                trapped += max(0, height - heightMap[nx][ny]);

                // Add neighbor to heap
                pq.push({max(height, heightMap[nx][ny]), nx, ny});
            }
        }

        return trapped;
    }
};