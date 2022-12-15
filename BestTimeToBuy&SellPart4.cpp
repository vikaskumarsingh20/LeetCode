You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
  
  
  //SOLUTION GIVEN BELOW 
  
  class Solution {
public:
       int solveRec(int index , int buy , vector<int>&prices, int limit){
         //base case
         if(index == prices.size())
           return 0;

           if(limit == 0)
            return 0;

          int profit = 0;   // buy = 0 -> not allowed , buy = 1 -> allowed
        if(buy){
        profit = max((-prices[index] + solveRec(index+1 ,0 , prices ,limit)) ,(0+solveRec(index+1 , 1 , prices ,limit)));
        }
        else{
            profit = max((+prices[index]+solveRec(index+1 ,1, prices ,limit-1)) , (0+solveRec(index+1 ,0, prices ,limit)));
        }

        return profit;
     }

          int solveMem(int index , int buy  ,vector<int>&prices, int limit ,vector<vector<vector<int>>>&dp){
          if(index >= prices.size())
            return 0;

        if(limit == 0)
          return 0;
        
        if(dp[index][buy][limit] != -1)
          return dp[index][buy][limit];

          int profit = 0;  
        if(buy){
        profit = max((-prices[index] + solveMem(index+1 ,0 , prices ,limit,dp)) ,(0+solveMem(index+1 , 1 , prices ,limit ,dp)));
        }
        else{
            profit = max((+prices[index]+solveMem(index+1 ,1, prices ,limit-1,dp)) , (0+solveMem(index+1 ,0, prices ,limit,dp)));
        }

        return dp[index][buy][limit] = profit;
     }


        int solveTab(vector<int>&prices , int k){
       int  n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2 , vector<int>(k+1,0)));
        
        for(int index = n-1;index>=0;index--){
            for(int buy =0;buy <=1;buy++){
                for(int limit = 1;limit <= k;limit++){
                          int profit = 0;    
                    if(buy){
                    profit = max((-prices[index] +  dp[index+1][0][limit]) ,(0+ dp[index+1][1][limit]));
                    }
                    else{
                        profit = max((+prices[index]+ dp[index+1][1][limit-1]) , (0+dp[index+1][0][limit]));
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][k];
 
     }
    
 int solveSpaceOptimization(vector<int>&prices,int k){
       int  n = prices.size();

        vector<vector<int>> curr(2,vector<int>(k+1,0));
        vector<vector<int>>next (2, vector<int>(k+1,0));
        
        for(int index = n-1;index>=0;index--){
            for(int buy =0;buy <=1;buy++){
                for(int limit = 1;limit <= k;limit++){
                          int profit = 0;    
                    if(buy){
                    profit = max((-prices[index] +  next[0][limit]) ,(0+ next[1][limit]));
                    }
                    else{
                        profit = max((+prices[index]+ next[1][limit-1]) , (0+next[0][limit]));
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][k];
 
     }

    int maxProfit(int k, vector<int>& prices) {
        // return solveRec(0 ,1, prices ,2, k);
          int n = prices.size();
            vector<vector<vector<int>>> dp(n,vector<vector<int>>(2 , vector<int>(k+1,-1)));
         return solveMem(0 ,1, prices , k, dp);

        // return solveSpaceOptimization(prices , k);
        //   return solveTab(prices , k);
    }
};
