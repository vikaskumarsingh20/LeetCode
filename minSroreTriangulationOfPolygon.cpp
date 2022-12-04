class Solution {
public:
    
    int solveRec(vector<int>&values , int i ,int j){
        // base case 
        if(i+1 == j)   // can't make triangle from 2 points
            return 0;
       
           int ans = INT_MAX;
        for(int k = i+1 ;k<j;k++){   // to run for 3rd point from next to last
         
            // recursion relation 
            ans = min(ans ,values[i]*values[j]*values[k] + solveRec(values , i ,k) +solveRec(values ,k , j) );
        }
        return ans;
    }
    
         //Top Down Approach
        int solveMem(vector<int>&values , int i ,int j , vector<vector<int>>&dp){
        // base case 
        if(i+1 == j)   // can't make triangle from 2 points
            return 0;
       
            if(dp[i][j] != -1)  // alredy exist then simply return
                return dp[i][j];
        
           int ans = INT_MAX;
        for(int k = i+1 ;k<j;k++){  // to run for 3rd point from next to last
         
            // recursion relation 
            ans = min(ans ,values[i]*values[j]*values[k] + solveMem(values , i ,k,dp) +solveMem(values ,k , j,dp) );
        }
        dp[i][j] = ans;
            return dp[i][j];
    }
     
    // Bottom Up Approach
 int solveTab(vector<int>&values ){
   
             int n = values.size();
             vector<vector<int>>dp(n, vector<int>(n+1, 0));
           
           for(int i = n-1 ;i>=0;i--){
               for(int j = i+2 ;j < n;j++){  // i+2, for atleat 3 points is reqiured for triangle 
                   
                    int ans = INT_MAX;
                  for(int k = i+1 ;k<j;k++){  
         
            // recursion relation 
               ans = min(ans ,values[i]*values[j]*values[k] + dp[i][k] + dp[k][j]);
        }
         dp[i][j] = ans;

               }
           }
          return dp[0][n-1]; 
    }
    
    int minScoreTriangulation(vector<int>& values) {
        
        // int n = values.size();
        // return solveRec(values , 0 , n-1);   // FOR RECUSION ONLY 
         
       //  int n = values.size();
       // vector<vector<int>> dp(n, vector<int>(n+1 ,-1));   // RECURSION + MEMORIZATION
       //  return solveMem(values , 0 , n-1 , dp);
        
        int n = values.size();
        return solveTab(values);
    }
};
