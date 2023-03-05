Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation:

Knight takes 3 step to reach from 
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
 

 

Your Task:
You don't need to read input or print anything. Your task is to 
  complete the function minStepToReachTarget() which takes the initial position of Knight (KnightPos), 
the target position of Knight (TargetPos), and the size of the chessboard (N) as input parameters and returns
the minimum number of steps required by the knight to reach from its current position to the given target position or return -1 if its not possible.

 

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).
  

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
    // to check is it valid not out of the box 
        bool isValid(int i, int j, int n, vector<vector<bool>>&visited){
        if(i>=0 && i<n && j>=0 && j<n && visited[i][j] == false){
            return true;
        }
        return false;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int n = N;
	    // why -1? me made it 0-indexed and question given 1-indexed
	    int tx = TargetPos[0]-1, ty = TargetPos[1]-1;
	    int x1 = KnightPos[0]-1, y1 = KnightPos[1]-1;
	    
	    // if matched exact position then return
	    if(x1 == tx && y1 == ty) return 0;
	    
	    // take 2D vector for visiting and maka all false that means not visited
	    vector<vector<bool>>visited(n, vector<bool>(n, false));
	    
	    queue<pair<int, int>>q;
	    q.push({x1, y1});
	    visited[x1][y1] = true; // visited
	    
	    int ans = 0;
	    while(!q.empty()){
	        
	        int size = q.size();
	         ans++;
	        while(size != 0){
	            pair<int,int>p = q.front();
	            q.pop();
	            
	            int xx = p.first;
	            int yy = p.second;
	            
	    // here total 8 moves 
	   //[[1,2],[1,-2],[-1,2],[-1,-2],[2,1],[-2,1],[2,-1],[-2,-1]]
	   
	            int ax[8] = {1, 1, -1, -1, 2, -2, 2, -2};
	            int ay[8] = {2, -2, 2, -2, 1, 1, -1, -1};
	            
	            for(int i=0; i<8; i++){
	                int nx = xx + ax[i];
	                int ny = yy + ay[i];
	                // found that position ,return ans
	                if(nx == tx && ny == ty) return ans;
	                
	                if(isValid(nx, ny, n, visited)){
	                    visited[nx][ny] = true;
	                    q.push({nx, ny});
	                }
	            }
	           
	            size--;
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
