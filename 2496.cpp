class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int res = 0;
        for (auto str : strs) {
            int slen = 0, nlen = 0, num = 0;
            for (auto s : str) {
                slen++;
                if (isdigit(s)) {
                    nlen++;
                    num = num * 10 + s - '0';
                }
            }
            if (nlen == slen) res = max(num, res);
            else res = max(res, slen);
        }
        return res;
    }
};
