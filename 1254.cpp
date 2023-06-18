class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        function<bool(int, int)> dfs = [&](int x, int y) -> bool {
            if (x < 0 || y < 0 || x >= m || y >= n) {
                return false;
            }
            if (grid[x][y] != 0) {
                return true;
            }
            grid[x][y] = -1;
            bool ret1 = dfs(x - 1, y);
            bool ret2 = dfs(x + 1, y);
            bool ret3 = dfs(x, y - 1);
            bool ret4 = dfs(x, y + 1);
            return ret1 && ret2 && ret3 && ret4;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && dfs(i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
