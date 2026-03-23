// #include "../leetcode.h"

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> tmp(k, 0); // vector of length k, init all=0
        int i = 0;

        while (i >= 0){
            // Increment element at index i
            tmp[i]++;

            // Move index to the left if the element at index i has exceeded n.
            if(tmp[i] > n) 
                i--;

            // If the index is at the end of the vector tmp,
            // then (because the other conditions are obeyed,) 
            // we know we have a valid combination, so push it
            // to our res vector<vector<>>
            else if( i==k-1){
                res.push_back(tmp);
            }

            // Move index to the right and set the element at
            // that index equal to the element at the previous
            // index.

            // Because of the increment at the beginning of this
            // while loop, we ensure that the element at this index
            // will be at least one more than its neighbor to 
            // the left.
            else{
                i++;
                tmp[i] = tmp[i - 1];
            }
        }

        return res;
    }

};
