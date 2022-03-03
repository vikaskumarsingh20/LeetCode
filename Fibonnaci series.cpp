The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

 

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
  
  code*****
  
  class Solution {
public:
    int fib(int n) {
        
        //BY RECURANCE THIS IS NOT THE OPTIMAL SOLUTION ...
        
        // if(n==0 || n==1) return n;
        // else  return fib(n-1)+fib(n-2);
        
        //BY DYNAMIC PROGRAMMUING THIS IS EFFICIENT METHOD FOR THIS PROGRAM
   int dp[n+2]; 
    
   dp[0] = 0;
   dp[1] = 1;
   for (int i = 2; i <= n; i++) {
      dp[i] = dp[i-1] + dp[i-2];  
      
   }
   return dp[n];
}


};
