class Solution {
public:
    bool isValid(string s) {
        string st;
        for (auto item : s) {
            st.push_back(item);
            if (st.size() >= 3 && st.substr(st.size() - 3, 3) == "abc") {
                st.erase(st.end() - 3, st.end());
            }
        }
        return !st.size();
    }
};
