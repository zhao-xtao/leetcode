class Solution {
public:
    int countTime(string time) {
        int res = 1;
        for (int i = 4; i >= 3; i--) {
            if (i == 4 && time[i] == '?') res *= 10;
            if (i == 3 && time[i] == '?') res *= 6;
        }
        for (int i = 1; i >= 0; i--) {
            if (i) {
                if (time[1] == '?' && time[0] == '?') {
                    res *= 24;
                    break;
                }
                else if (time[1] == '?' && (time[0] == '1' || time[0] == '0')) res *= 10;
                else if (time[1] == '?' && time[0] == '2') res *= 4;
            } else {
                if (time[0] == '?' && time[1] <= '3') res *= 3;
                else if (time[0] == '?' && time[1] > '3') res *= 2;
            }
        }
        return res;
    }
};
