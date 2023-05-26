class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        int n = grid.size();
        vector<vector<int> > dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 1;
        while(!q.empty()) {
            auto x = q.front().first;
            auto y = q.front().second;
            q.pop();
            if (x == n - 1 && y == n - 1) {
                return dist[x][y];
            }
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (x + i < 0 || x + i >= n || y + j < 0 || y + j >= n) continue;
                    if (grid[x + i][y + j] == 1 || dist[x + i][y + j] <= dist[x][y] + 1) continue;
                    dist[x + i][y + j] = dist[x][y] + 1;
                    q.push({x + i, y + j});
                }
            }
        }
        return -1;
    }
};
