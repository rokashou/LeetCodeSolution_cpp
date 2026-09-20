/* 3483. Unique 3-Digit Even Numbers */
/* 0ms, 28.75MB */

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // Count frequency of each digit value (0-9).
        int cnt[10] = {0};
        for (int d : digits) {
            ++cnt[d];
        }

        int answer = 0;
        // h: hundreds digit, must be 1-9 (no leading zero).
        for(int h = 1; h<=9; ++h){
            if (cnt[h] == 0) continue;
            // t: tens digit, can be 0-9.
            for (int t = 0; t <= 9; ++t) {
                int needT = (t == h) ? 2 : 1;
                if (cnt[t] < needT) continue;
                // u: units digit, must be even.
                for (int u = 0; u <= 8;u+=2){
                    int needU = 1 + (u == h) + (u == t);
                    if(cnt[u] >= needU) {
                        ++answer;
                    }
                }
            }
        }
        return answer;
    }
};
