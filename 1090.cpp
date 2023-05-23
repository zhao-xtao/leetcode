class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int, int> > a;
        for (int i = 0; i < values.size(); i++) {
            a.push_back({values[i], labels[i]});
        }
        sort(a.begin(), a.end(), [&](pair<int, int> x, pair<int, int> y) { return x.first > y.first; });
        int sum = 0;
        unordered_map<int, int> mp;
        for (auto t : a) {
            if (numWanted == 0) break;
            if (mp[t.second] < useLimit) {
                sum += t.first;
                numWanted -= 1;
                mp[t.second] += 1;
            }
        }
        return sum;
    }
};
