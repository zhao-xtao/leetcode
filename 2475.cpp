class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int res = 0, n = nums.size(), t = 0;
        unordered_map<int, int> cnt;
        for (auto num : nums) cnt[num]++;
        for (auto iter = cnt.begin(); iter != cnt.end(); iter++) {
            res += t * iter->second * (n - t - iter->second);
            t += iter->second;
        }
        return res;
    }
};
