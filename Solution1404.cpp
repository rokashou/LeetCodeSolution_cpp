#include "../leetcode.h"

// 1404. Number of Steps to Reduce a Number in Binary Representation to One

class Solution
{
private:
    void addOne(string& s)
    {
        int i = s.size() - 1;

        // Iterating while the character is 1 and changing to 0 to carry the 1.
        while(i >= 0 && s[i] != '0'){
            s[i] = '0';
            i--;
        }

        if(i<0){
            s = '1' + s;
        }else{
            s[i] = '1';
        }
    }

    void divideByTwo(string& s){ s.pop_back(); }

public:
    int numSteps(string s)
    {
        int N = s.size();
        int count = 0;
        while(s.size() > 1){
            N = s.size();

            if(s[N-1] == '0'){
                divideByTwo(s);
            }else{
                addOne(s);
            }

            count ++;
        }
        return count;
    }
};

class Solution2 // Greedy
{

public:
    int numSteps(string s)
    {
        int N = s.size();

        int count = 0;
        int carry = 0;
        for (int i = N - 1; i > 0;i--){
            if(((s[i]-'0')+carry)%2){
                count += 2;
                carry = 1;
            }else{
                count++;
            }
        }
        return count + carry;
    }
};
