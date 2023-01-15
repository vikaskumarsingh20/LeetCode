547. Number of Provinces
Medium
6.9K
279
Companies
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
  
  
  

class Solution {
public:
    void dfs(int root, vector<int>& vis, vector<int> adj[]){
        if (vis[root])return;
        vis[root]=1;
        for (auto val : adj[root]){
            dfs(val,vis,adj);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        //undirected graph
        int n= isConnected.size();
        int cnt=0;
        vector<int> vis(n+1,0);
        // create adjacency list:
        vector<int> adj[n+1];
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (i!=j && isConnected[i][j]){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        for (int i=1; i<=n; i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                cnt++;
            }
        }
        return cnt;
    }
};
