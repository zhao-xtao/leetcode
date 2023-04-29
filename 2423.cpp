class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> pr;
        for (auto w : word) pr[w] ++;
        for (auto item = pr.begin(); item != pr.end(); item ++) {
            pr[item->first] --;
            set<int> st;
            for (auto it = pr.begin(); it != pr.end(); it ++) {
                if (it->second) st.insert(it->second);
            }
            if (st.size() == 1) return true;
            pr[item->first] ++;
        }
        return false;
    }
};
