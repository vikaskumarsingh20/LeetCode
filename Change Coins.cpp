You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
  *****************************************
  CODE 
  class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(); // number of coins
        
        int dp[n+1][amount+1]; // initialize dp 
        for(int i=0;i<n+1;i++){ 
            for(int j=0;j<amount+1;j++){
                if(j==0) dp[i][j]=0; // marking the 0th column as 0
                if(i==0) dp[i][j]=INT_MAX-1; // marking the 0th row as INT_MAX-1
            }
        }
        // marking the first row and first column
        for(int i=1,j=1;j<amount+1;j++){
            if(j%coins[0]==0) dp[i][j]=j/coins[0];
            else dp[i][j] = INT_MAX-1;
        }
        // marking from the second row and first column
        for(int i=2;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1]<=j){
                    dp[i][j]= min(1+dp[i][j-coins[i-1]], dp[i-1][j]); // if the coin is less than the amount, then we can use it or we can use the previous row
                }
                else
                    dp[i][j]=dp[i-1][j]; // if the coin is greater than the amount, then we can use the previous row
            }
        }
        
        if(dp[n][amount]==INT_MAX-1) return -1; // if the amount is not possible
        else return dp[n][amount];
    }
};
