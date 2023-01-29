343. Integer Break
Medium
3.5K
357
Companies
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

 

Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
  //CODE
  

class Solution {
private:
    int Memorization(int n,vector<int>& dp){
        if(n==0 || n==1)
             return 1;
        
        if(dp[n]!=-1)
             return dp[n];
        
          int maxi = 0;
        for(int ind=1;ind<n;ind++){
            int temp = max(ind*(n-ind), ind * Memorization(n-ind,dp));
               maxi = max(maxi,temp);
        }
        return dp[n]=maxi;
    }
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return Memorization(n,dp);
    }
};
