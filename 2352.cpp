class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> pr;
        for (auto row : grid) pr[row] ++;
        int res = 0;
        for (int i = 0; i < n; i++) {
            vector<int> t;
            for (int j = 0; j < n; j++) {
                t.push_back(grid[j][i]);
            }
            if (pr.count(t)) res += pr[t];
        }
        return res;
    }
};
