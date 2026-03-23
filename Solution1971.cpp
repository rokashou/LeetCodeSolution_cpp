#include "../leetcode.h"

class DisjointSetUnion {
    // Disjoint Set Union, with rank
    vector<int> parent, rank;
    public:
    DisjointSetUnion(int n){
        parent.resize(n);
        rank.resize(n);
        iota(parent.begin(), parent.end(), 0); // defined in header <numeric>
    }

    int find(int x){
        if(x!=parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool Union(int x, int y){
        int xp = find(x);
        int yp = find(y);
        if(xp==yp)
            return true;
        else{
            if(rank[xp] > rank[yp])
                parent[yp] = xp;
            else if(rank[xp] < rank[yp])
                parent[xp] = yp;
            else{
                parent[yp] = xp;
                rank[xp]++;
            }
            return false;
        }
    }
};

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        DisjointSetUnion uf(n);
        for (int i = 0; i < edges.size();i++){
            uf.Union(edges[i][0], edges[i][1]);
        }
        return uf.Union(source, destination);
    }
};