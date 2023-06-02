class Solution {
public:
    bool check(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        int pr[100005];
        memset(pr, 0, sizeof(pr));
        int idx = 1;
        for (auto word: words) {
            char a = word[0], b = word[word.size() - 1];
            pr[idx] += pr[idx - 1];
            if (check(a) && check(b)) pr[idx] += 1;
            idx += 1;
        }
        for (auto querie : queries) {
            int l = querie[0] + 1, r = querie[1] + 1;
            ans.push_back(pr[r] - pr[l - 1]);
        }
        return ans;
    }
};
