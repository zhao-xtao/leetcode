class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans_id = logs[0][0], ans_time = logs[0][1];
        for (int i = 1; i < logs.size(); i ++) {
            int id = logs[i][0], time = logs[i][1] - logs[i - 1][1];
            if (ans_time == time && id < ans_id) ans_id = id;
            if (ans_time < time) ans_time = time, ans_id = id;
        }
        return ans_id;
    }
};
