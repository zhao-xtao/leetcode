class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;
        for (auto num : nums) {
            if (num % 6 == 0) {
                sum1 += num;
                sum2++;
            }
        }
        return sum2 ? sum1 / sum2 : 0;
    }
};
