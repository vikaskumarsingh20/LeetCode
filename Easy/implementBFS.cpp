//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
            Expected Time Complexity: O(V + E)
            Expected Auxiliary Space: O(V)
    
   void bfs(vector<int> adj[],vector<int>&visited, vector<int>&ans, int node ){
       
        queue<int> q;
        
        q.push(node);
        visited[node]=true;

        while(!q.empty()){

            int frontnode=q.front();

               q.pop();

            ans.push_back(frontnode);

            for(auto i: adj[frontnode]){

                if(!visited[i]){

                    q.push(i);

                    visited[i]=true;
                }
            }
        }
    }

    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
         vector<int>ans;
         
    //   unordered_map<int ,bool>visited;
    vector<int>visited(V+1,false);
        bfs(adj,visited,ans,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
