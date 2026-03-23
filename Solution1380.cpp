#include "../leetcode.h"

class Solution
{
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> result;
        for (int r = 0; r < matrix.size ();r++){
            int c = FindRowMin (matrix, r);
            int temp = FindColumnMax (matrix, c);
            if(r==temp){
                result.push_back (matrix[r][c]);
                return result;
                }
            }
        return result;
    }

private:
    int FindRowMin(vector<vector<int>>& matrix, int row) {
        int temp = 100001;
        int col = -1;
        for (int i = 0; i < matrix[row].size ();i++){
            if(temp > matrix[row][i]){
                temp = matrix[row][i];
                col = i;
            }
        }
        return col;
    }

    int FindColumnMax(vector<vector<int>>& matrix, int column) {
        int temp = 0;
        int row = -1;
        for (int i = 0; i < matrix.size ();i++){
            if(temp < matrix[i][column]){
                temp = matrix[i][column];
                row = i;
            }
        }
        return row;
    }
};