class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> cnt;
        int res = 0;
        for (auto t : time) {
            res += cnt[(60 - t % 60) % 60];
            ++cnt[t % 60];
        }
        return res;
    }
};
