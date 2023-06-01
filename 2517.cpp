class Solution {
public:
    bool check(vector<int> &price, int k, int mid) {
        int prev = INT_MIN >> 1, cnt = 0;
        for (int p : price) {
            if (p - prev >= mid) {
                cnt++;
                prev = p;
            }
        }
        return cnt >= k;
    }

    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int l = 0, r = price[n - 1] - price[0];
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(price, k, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
