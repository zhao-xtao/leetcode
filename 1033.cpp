class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int Max = max(a, max(b, c)), Min = min(a, min(b, c)), Mid = a + b + c - Max - Min;
        int ansMin, ansMax = Max - Mid - 1 + Mid - Min - 1;
        if (Max == Mid + 1 && Mid == Min + 1) ansMin = 0;
        else if (Mid - Min <= 2 || Max - Mid <= 2) ansMin = 1;
        else ansMin = 2;
        return {ansMin, ansMax};
    }
};
