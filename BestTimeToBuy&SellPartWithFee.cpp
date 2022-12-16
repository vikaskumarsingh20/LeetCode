You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
  
  // SOLUTION GIVEN BELOW 


class Solution {
public:

int solveRec(int index , int buy , vector<int>&prices ,int fee){
         //base case
         if(index == prices.size())
           return 0;

          int profit = 0;   // buy = 0 -> not allowed , buy = 1 -> allowed
        if(buy){
        profit = max((-prices[index] + solveRec(index+1 ,0 , prices, fee) -fee) ,(0+solveRec(index+1 , 1 , prices,fee)));
        }
        else{
            profit = max((+prices[index]+solveRec(index+1 ,1, prices,fee)) , (0+solveRec(index+1 ,0, prices,fee)));
        }

        return profit;
     }

 int solveMem(int index , int buy , vector<int>&prices,int fee ,vector<vector<int>>&dp){
         //base case
         if(index == prices.size())
           return 0;

        if(dp[index][buy] != -1)
           return dp[index][buy];

          int profit = 0;   
        if(buy){
        profit = max((-prices[index] + solveMem(index+1 ,0 , prices,fee,dp) -fee) ,(0+solveMem(index+1 , 1 , prices,fee ,dp)));
        }
        else{
            profit = max((+prices[index]+solveMem(index+1 ,1, prices,fee,dp)) , (0+solveMem(index+1 ,0, prices,fee,dp)));
        }

        return dp[index][buy] =  profit;
     }

         int solveTab(vector<int>&prices ,int fee){

         int n = prices.size();
       vector<vector<int>>dp(n+1 ,vector<int>(2,0));  // base case handled here
        
        for(int index = n-1; index >=0;index--){
            for(int buy = 0;buy<= 1;buy++){

            int profit = 0;    
            if(buy){       // buy it or skip it 
            profit = max((-prices[index] +  dp[index+1][0] -fee) ,(0+ dp[index+1][1]));
            }
            else{
                profit = max((+prices[index]+ dp[index+1][1]) , (0+dp[index+1][0]));
            }

            dp[index][buy] =  profit;
            }
        }
        return dp[0][1];  // index become -> 0, buy -> 0
     }

     int solveSpaceOptimization(vector<int>&prices , int fee){
          int n = prices.size();
  
            vector<int>curr(2, 0);  // Here only 4 variable can say
            vector<int>next(2, 0);
        
        for(int index = n-1; index >=0;index--){
            for(int buy = 0;buy<= 1;buy++){

            int profit = 0;    
            if(buy){
            profit = max((-prices[index] +  next[0]  -fee) ,(0 + next[1]));
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

    int maxProfit(vector<int>& prices, int fee) {
        // return solveRec(0,1 ,prices,fee);
        // return solveTab(prices , fee);
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2 ,-1));
        return solveMem(0 , 1 , prices ,fee ,dp);
    }
};
