#include "../leetcode.h"
#include <unordered_map>

class Solution{
private:
    unordered_map<int, vector<int>> graph;
    vector<int> count; // the number of nodes in the subtree rooted at node.
    vector<int> res; // The sum of distances of all nodes in the subtree rooted at node.


    // 1st DFS: to Calculate Counts and Partial Distances
    void dfs(int node, int parent){
        for(int child : graph[node]){
            if(child != parent){
                dfs(child, node);
                count[node] += count[child];
                res[node] += res[child] + count[child];
            }
        }
    }

    // 2nd DFS: Adjustments
    void dfs2(int node, int parent){
        for(int child : graph[node]){
            if(child != parent){
                res[child] = res[node] - count[child] + (count.size() - count[child]);
                dfs2(child, node);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges){
        graph.clear();
        count = vector<int>(n, 1);
        res = vector<int>(n, 0);

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1);
        dfs2(0, -1);

        return res;
    }
};

class Solution_dfs
{
private:
    vector<vector<int>> v;
    vector<int> counter, res;

    void dfs(int i, int p = -1){
        for(auto u : v[i]){
            if(u==p) continue;
            dfs(u, i);
            counter[i] += counter[u];
            res[i] += res[u] + counter[u];
        }
        counter[i] += 1;
    }

    void dfs2(int i, int n, int p = -1){
        for(auto u : v[i]){
            if(u==p) continue;
            res[u] = res[i] - counter[u] + n - counter[u];
            dfs2(u, n, i);
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        v.resize(n);
        for (int i = 0; i < n - 1;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        res.resize(n);
        counter.resize(n);
        dfs(0);
        dfs2(0, n);
        return res;
    }
};