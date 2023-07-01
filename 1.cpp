class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pr;
        for (int i = 0; i < nums.size(); i++) {
            int x = target - nums[i];
            if (pr.count(x)) return {pr[x], i};
            pr[nums[i]] = i;
        }
        return {};
    }
};
