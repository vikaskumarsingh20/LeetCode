322. Coin Change
Medium
15.1K
350
Companies
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
  
  //CODE 
  class Solution {
    int dp[13][10001];
    int  Memorization(vector<int>& coins, int i, int amount, int n){
      //matched 
        if(amount==0){
            return 0;
        }
      //out of bound
        if(i==n){
            return INT_MAX-1;
        }
      //store it 
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        int cnt1=INT_MAX-1; int cnt2=INT_MAX-1;
      // when valid 
        if(coins[i]<=amount){
            cnt1=1+Memorization(coins, i, amount-coins[i], n);
        }
            cnt2=Memorization(coins, i+1, amount, n);
      //find min coins 
        return dp[i][amount]=min(cnt1, cnt2);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int z = Memorization(coins, 0, amount, coins.size());
        if(z==INT_MAX-1){
            return -1;
        }
        return z;
    }
};
