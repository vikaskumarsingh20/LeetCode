Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
  
  //  SOLUTION GIVEN BELOW
  class Solution {
public:
    
    int solveRec(string &a , string &b , int i , int j){
        if(i ==a.length() )  // i reached out of length then not matched
            return 0;
        if(j == b.length()) // same 4 it 
            return 0;
        
        int ans = 0;
        if(a[i] == b[j]) // if the string is matched 
            ans = 1+ solveRec(a ,b , i +1,j +1); // 1 add for 1 case and check for next strings
        else             
            ans =   max(solveRec(a,b,i +1 ,j) , solveRec(a ,b, i ,j +1)); // i is static and j+1 for next mathcing string and same to j.
        
        return ans;
    }

    int solveMem(string &a, string &b ,int i , int j , vector<vector<int>>&dp){
        if(i ==a.length() )
             return 0;
        if(j == b.length())
            return 0;

        if(dp[i][j] != -1)
          return dp[i][j];
        
        int ans = 0;
        if(a[i] == b[j])
            ans = 1+ solveMem(a ,b , i +1,j +1 ,dp);
        else
            ans =   max(solveMem(a,b,i +1 ,j ,dp) , solveMem(a ,b, i ,j +1,dp));
        
        return dp[i][j] = ans;
    }

int solveTab(string &a , string &b){

    int n = a.length();
    int m = b.length();

    vector<vector<int>> dp( n+1 , vector<int>(m+1 ,0));

    for(int i = n-1 ;i >=0;i--){
        for(int j = m-1 ;j>=0;j--){

          int ans = 0;
        if(a[i] == b[j])
            ans = 1+  dp[i+1][j+1];
        else
            ans =   max(dp[i+1][j] , dp[i][j+1]);

        dp[i][j] = ans;
        }  
    }
    return dp[0][0];
}

int solveSapceOptimization(string &a , string &b){

    int n = a.length();
    int m = b.length();

    // vector<vector<int>> dp( n+1 , vector<int>(m+1 ,0));
    vector<int>curr(n+1,0);
    vector<int>next(m+1,0);

    for(int i = n-1 ;i >=0;i--){
        for(int j = m-1 ;j>=0;j--){

          int ans = 0;
        if(a[i] == b[j])
            ans = 1+  next[j+1];
        else
            ans =   max(next[j] ,curr[j+1]);

        curr[j] = ans;
        }  
        next = curr;
    }
    return next[0];
}

    int longestCommonSubsequence(string text1, string text2) {
          int n = text1.size();
        // return solve(text1 , text2 ,0 , 0);
        // vector<vector<int>>dp(n+1,vector<int>(n+2 ,-1));
        //   return solveMem(text1 , text2,0 ,0 ,dp);
        return solveTab(text1 , text2);
        // return solveSapceOptimization(text1, text2);
    }
};
