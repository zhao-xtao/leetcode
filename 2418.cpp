class Solution {
public:

    struct Data {
        string name;
        int h;
    };

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<Data> st;
        for (int i = 0; i < names.size(); i ++) {
            Data temp;
            temp.name = names[i];
            temp.h = heights[i];
            st.push_back(temp);
        }  
        sort(st.begin(), st.end(), [&](const Data &a, const Data &b) {
            return a.h > b.h;
        });
        vector<string> res;
        for (auto t : st) {
            res.push_back(t.name);
        }
        return res;
    }
};
