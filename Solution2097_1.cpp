#include "../leetcode.h"

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs) {

        vector<vector<int>> final_result;

        unordered_map<int, deque<int>> adjacencyMatrix;
        unordered_map<int, int> inDegree, outDegree;

        // Build the adjacency list and track in-degrees and out-degrees
        for (const auto &pair : pairs) {
            int start = pair[0], end = pair[1];
            adjacencyMatrix[start].push_back(end);
            outDegree[start]++;
            inDegree[end]++;
        }

        vector<int> result_list;

        // Find the start node (outDegree == 1 + inDegree)
        int startNode = -1;
        for (const auto &entry : outDegree) {
            int node = entry.first;
            if (outDegree[node] == inDegree[node] + 1) {
                startNode = node;
                break;
            }
        }

        // If no such node exists, start from the first pair's first element
        if (startNode == -1) {
            startNode = pairs[0][0];
        }

        stack<int> nodeStack;
        nodeStack.push(startNode);

        // Iterative DFS using stack
        while(!nodeStack.empty()){
            int node = nodeStack.top();
            if(!adjacencyMatrix[node].empty()){
                // visit the next node
                int nextNode = adjacencyMatrix[node].front();
                adjacencyMatrix[node].pop_front();
                nodeStack.push(nextNode);
            }else{
                // No more neighbors to visit, add node to result
                result_list.push_back(node);
                nodeStack.pop();
            }
        }

        // Reverse the result since DFS gives us the path in reverse
        reverse(result_list.begin(), result_list.end());

        // Construct the result pairs
        for (int i = 1; i < result_list.size(); i++) {
            final_result.push_back({result_list[i - 1], result_list[i]});
        }

        return final_result;
    }
};