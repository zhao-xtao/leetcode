class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> qsum, wsum;
        for (auto querie : queries) {
            qsum.emplace_back(f(querie));
        }
        for (auto word : words) {
            wsum.emplace_back(f(word));
        }
        sort(wsum.begin(), wsum.end());
        vector<int> res;
        for (auto q : qsum) {
            int l = 0, r = wsum.size() - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (wsum[mid] > q) r = mid;
                else l = mid + 1;
            }
            if (wsum[l] > q) res.emplace_back(wsum.size() - l);
            else res.emplace_back(0);
        }
        return res;
    }

    int f(string &str) {
        int sum = 0;
        char c = 'z';
        for (auto s : str) {
            if (s > c) continue;
            else if (s < c) {
                c = s;
                sum = 1;
            } else sum++;
        }
        return sum;
    }
};
