
/* 
  2904. Shortest Beautiful Substring 
  Runtime: 0 ms, faster than 100.00% of C++ online submissions for Shortest Beautiful Substring.
  Memory Usage: 8.74 MB, less than 64.74% of C++ online submissions for Shortest Beautiful Substring.
*/

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, ones = 0;
        string ans = "";

        for (int right = 0; right < n; right++) {
            if (s[right] == '1') ones++;

            while (ones > k || (ones == k && s[left] == '0')) {
                if (s[left] == '1')  ones--;
                left++;
            }

            if (ones == k) {
                int len = right - left + 1;
                if (ans.empty() || len < (int)ans.size()) {
                    ans = s.substr(left, len);
                } else if (len == (int)ans.size()) {
                    string cand = s.substr(left, len);
                    if (cand < ans) ans = cand;
                }
            }
        }
        return ans;
    }
};

