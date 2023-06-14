class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int res = 0, rigth = 0, n = flips.size();
        for (int i = 0; i < n; i++) {
            rigth = max(flips[i], rigth);
            if (rigth == i + 1) res ++;
        }
        return res;
    }
};
