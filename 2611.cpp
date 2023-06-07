class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        if(k == reward1.size()) return accumulate(reward1.begin(), reward1.end(), 0);
        int ans = 0;
        vector<int> diffs((int)reward1.size());
        for (int i = 0; i < reward2.size(); i++) {
            ans += reward2[i];
            diffs[i] = reward1[i] - reward2[i];
        }
        sort(diffs.begin(), diffs.end(), greater<int>());
        for (int i = 0; i < k; i++) {
            ans += diffs[i];
        }
        return ans;
    }
};
