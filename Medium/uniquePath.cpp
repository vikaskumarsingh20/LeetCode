There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
//CODE
class Solution {
public:
    
    
    int solveRec(int si,int sj,int ei,int ej){
        //base case .when reached
        if(si==ei && sj==ej)
          return 1;
          //out of range
        if(si>ei || sj>ej)
          return 0;
        //recursive call
       int op1 = solveRec(si+1,sj,ei,ej);
       int op2 = solveRec(si,sj+1,ei,ej);
       return op1+op2;
    }
 
    int Memorization(vector<vector<int>>& dp, int& m, int& n, int i, int j){
         // Out of bounds
        if(i==m || j==n) 
          return 0; 
          //reached the end
        if(i==m-1 && j==n-1) 
          return 1;
          // store before
        if(dp[i][j]!=-1)
           return dp[i][j];
           
        dp[i][j] = Memorization(dp, m, n, i+1, j) + Memorization(dp, m, n, i, j+1);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return Memorization(dp, m, n, 0, 0);
    }
};
