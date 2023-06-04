class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        unordered_map<double, int> cnt;
        while (l < r) {
            cnt[(double)((nums[l] + nums[r]) / 2.0)] = 1;
            l ++;
            r --;
        }
        return cnt.size();
    }
};
