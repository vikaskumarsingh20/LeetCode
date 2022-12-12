
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
  
//   SOLUTION
  
  class Solution {
public:
  int solveMem(int n , vector<int>&dp){
        if(n <= 1)
           return 1;

      if(dp[n] != -1)
       return dp[n];

        int ans = 0 ;
     for(int i = 1 ;i<=n ;i++){
         ans  += solveMem(i-1 ,dp)*solveMem(n-i ,dp);
     }
     return dp[n] = ans;
  }

  int solveTab(int n){

     vector<int>dp(n+1, 0);
     dp[0]= dp[1] =1;
         
         //i->number of nodes
      for(int i=2;i<=n;i++){
          // root nodes
          for(int j = 1;j<= i;j++){
              dp[i] += dp[j-1]*dp[i-j];
          }
      }
      return dp[n];

  }
    int numTrees(int n) {
        // vector<int>dp(n+1 , -1);
        return solveTab(n);


    }
};
