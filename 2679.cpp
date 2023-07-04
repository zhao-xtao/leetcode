class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int res = 0;
        for (auto &num : nums) sort(num.begin(), num.end(), greater<int>());
        int n = nums.size(), m = nums[0].size();
        for (int j = 0; j < m; j++) {
            int s_max = 0;
            for (int i = 0; i < n; i++) s_max = max(s_max, nums[i][j]);
            res += s_max;
        }
        return res;
    }
};
