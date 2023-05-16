class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        vector<vector<int>> dp(d, vector<int>(n));
        for (int j = 0, ma = 0; j < n; ++j) {
            ma = max(ma, jobDifficulty[j]);
            dp[0][j] = ma;
        }
        for (int i = 1; i < d; ++i) {
            stack<pair<int, int>> st;
            for (int j = i; j < n; ++j) {
                int mi = dp[i - 1][j - 1];
                while (!st.empty() && jobDifficulty[st.top().first] < jobDifficulty[j]) {
                    mi = min(mi, st.top().second);
                    st.pop();
                }
                if (st.empty()) {
                    dp[i][j] = mi + jobDifficulty[j];
                } else {
                    dp[i][j] = min(dp[i][st.top().first], mi + jobDifficulty[j]);
                }
                st.emplace(j, mi);
            }
        }
        return dp[d - 1][n - 1];
    }
};
