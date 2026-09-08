/* 3870. Count Commas in Range */
/* 0ms, 8.65MB */
class Solution {
public:
    int countCommas(int n) { 
        return (n > 999) ? (n - 999) : 0; 
    }
};
