797. All Paths From Source to Target
Medium
6.2K
131
Companies
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

Example 1:


Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Example 2:


Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

//CODE

class Solution {
public:
    void dfs(vector<vector<int>>&graph, vector<vector<int>>&ans,vector<int>&path, int curr){
        // insert into path array
        path.push_back(curr);
        
        // if found the target then insert into path
       if(curr ==graph.size()-1){
           ans.push_back(path);
       }
       //otherwise
       else{
           for(auto x :graph[curr]){
               //call dfs
               dfs(graph, ans,path, x);
           }
       }
       // when matched target the pop for other path
       path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int> path;

        dfs(graph , ans , path , 0);
        return ans;
    }
};
