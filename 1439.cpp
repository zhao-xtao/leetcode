class Solution {
    vector<int> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> ans;
        priority_queue<tuple<int, int, int>> pq;
        int n = nums1.size(), m = nums2.size();
        pq.emplace(-nums1[0] - nums2[0], 0, 0);
        while (!pq.empty() && ans.size() < k) {
            auto [_, i, j] = pq.top();
            pq.pop();
            ans.push_back(nums1[i] + nums2[j]); 
            if (j == 0 && i + 1 < n)
                pq.emplace(-nums1[i + 1] - nums2[0], i + 1, 0);
            if (j + 1 < m)
                pq.emplace(-nums1[i] - nums2[j + 1], i, j + 1);
        }
        return ans;
    }

public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        vector<int> a = {0};
        for (auto &row: mat)
            a = kSmallestPairs(row, a, k);
        return a.back();
    }
};
