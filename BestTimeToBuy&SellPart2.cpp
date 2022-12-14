You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
  
  
  //SOLUTION GIVEN BELOW 
  
  class Solution {
public:
     int solveRec(int index , int buy , vector<int>&prices){
         //base case
         if(index == prices.size())
           return 0;

          int profit = 0;   // buy = 0 -> not allowed , buy = 1 -> allowed
        if(buy){
        profit = max((-prices[index] + solveRec(index+1 ,0 , prices)) ,(0+solveRec(index+1 , 1 , prices)));
        }
        else{
            profit = max((+prices[index]+solveRec(index+1 ,1, prices)) , (0+solveRec(index+1 ,0, prices)));
        }

        return profit;
     }

      int solveMem(int index , int buy , vector<int>&prices,vector<vector<int>>&dp){
         //base case
         if(index == prices.size())
           return 0;

        if(dp[index][buy] != -1)
           return dp[index][buy];

          int profit = 0;   
        if(buy){
        profit = max((-prices[index] + solveMem(index+1 ,0 , prices,dp)) ,(0+solveMem(index+1 , 1 , prices,dp)));
        }
        else{
            profit = max((+prices[index]+solveMem(index+1 ,1, prices,dp)) , (0+solveMem(index+1 ,0, prices,dp)));
        }

        return dp[index][buy] =  profit;
     }
        
     int solveTab(vector<int>&prices){

         int n = prices.size();
       vector<vector<int>>dp(n+1 ,vector<int>(2,0));  // base case handled here
        
        for(int index = n-1; index >=0;index--){
            for(int buy = 0;buy<= 1;buy++){

            int profit = 0;    
            if(buy){
            profit = max((-prices[index] +  dp[index+1][0]) ,(0+ dp[index+1][1]));
            }
            else{
                profit = max((+prices[index]+ dp[index+1][1]) , (0+dp[index+1][0]));
            }

            dp[index][buy] =  profit;
            }
        }
        return dp[0][1];  // index become -> 0, buy -> 0
     }

     int solveSpaceOptimization(vector<int>&prices){
          int n = prices.size();
  
            vector<int>curr(2, 0);  // Here only 4 variable can say
            vector<int>next(2, 0);
        
        for(int index = n-1; index >=0;index--){
            for(int buy = 0;buy<= 1;buy++){

            int profit = 0;    
            if(buy){
            profit = max((-prices[index] +  next[0]) ,(0 + next[1]));
            }
            else{
                profit = max((+prices[index]+ next[1]) , (0 + next[0]));
            
            }
          curr[buy] =  profit;
         }
         next = curr;
       }
        return next[1]; 
     }
    int maxProfit(vector<int>& prices) {
        // return solveRec(0 , 1 , prices);
        int n = prices.size();
        // vector<vector<int>> dp(n,vector<int>(2 ,-1));
        // return solveMem(0 , 1 , prices ,dp);
        // return solveTab(prices);
        return solveSpaceOptimization(prices);
    }
};
