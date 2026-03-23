class Solution{
    public:
    int passThePillow(int n, int time){
        int mod =  2 * (n - 1);
        int curr = time % mod;
        return 1 + (curr < n ? curr : mod - curr);
    }
};