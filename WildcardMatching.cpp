Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
  
  //SOLUTION IS GIVEN BELOW
  
  class Solution {
public:
   
   bool solveRec(string &str , string &pattern, int i , int j){
       //base case
       if(i==0 && j== 0)  // when both matched
         return true;

         if(i >0 && j == 0)  // remaining one of them
           return false;

        if(i== 0 && j>0){  //catch 
       for(int k = 1;k<=j;k++){
           if(pattern[k-1] != '*')
            return false;
       }
       return true;
        }
    
    if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')  // alset then do recursive call 
      return solveRec(str, pattern, i-1 , j-1);
    
    else if(pattern[j-1] == '*')  //  if * then there r multiple things 
               // if meet * then make it empty  , // if need any string then add with * and move on
     return (solveRec(str,pattern , i,j-1) || solveRec(str ,pattern , i-1 ,j));
    
    else
      return false;
     
   }

     bool solveMem(string &str , string &pattern, int i , int j,vector<vector<int>>&dp){
       //base case
       if(i==0 && j== 0)
         return true;

         if(i >0 && j == 0)
           return false;

        if(i== 0 && j>0){
       for(int k = 1;k<=j;k++){
           if(pattern[k-1] != '*')
            return false;
       }
       return true;
        }
    
    if(dp[i][j] != -1)
      return dp[i][j];
    
    if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
      return dp[i][j] = solveMem(str, pattern, i-1 , j-1 ,dp);
    
    else if(pattern[j-1] == '*')
     return dp[i][j] = (solveMem(str,pattern , i,j-1,dp) || solveMem(str ,pattern , i-1 ,j,dp));
    
    else
      return dp[i][j] = false;
     
   }
  
     bool solveTab(string &str , string &pattern){
      vector<vector<int>>dp(str.length()+1 ,vector<int>(pattern.length()+1,0));
       dp[0][0] =true;

      for(int j = 1;j<=pattern.length();j++){
           bool flag = true;
       for(int k = 1;k<=j;k++){
           if(pattern[k-1] != '*'){
            flag = false;
             break;
             }     
          }
       dp[0][j] = flag;
      }

      for(int i =1;i<=str.length();i++){
          for(int j =1;j<=pattern.length();j++){

         if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
           dp[i][j] = dp[i-1][j-1];
        
        else if(pattern[j-1] == '*')
          dp[i][j] = (dp[i][j-1] || dp[i-1][j]);
        
        else
         dp[i][j] = false;
          }
      }
      return dp[str.length()][pattern.length()];
     
   }

 bool solveSpaceOptimization(string A&str , string &pattern){

      vector<int> prev(str.length()+1,0);
      vector<int> curr(pattern.length()+1,0);

      prev[0] = true;

      for(int j = 1;j<=pattern.length();j++){
           bool flag = true;
       for(int k = 1;k<=j;k++){
           if(pattern[k-1] != '*'){
            flag = false;
             break;
             }     
          }
      prev[j] = flag;
      }

      for(int i =1;i<=str.length();i++){
          for(int j =1;j<=pattern.length();j++){

         if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
           curr[j] = prev[j-1];
        
        else if(pattern[j-1] == '*')
           curr[j] = (curr[j-1] || prev[j]);
        
        else
         curr[j] = false;
          }
          prev = curr;
      }
      return prev[pattern.length()];
     
   }

    bool isMatch(string s, string p) {
        // return solveRec(s ,p , s.length() ,p.length());  // compare with right side
        // vector<vector<int>>dp(s.length()+1 ,vector<int>(p.length()+1,-1)); //for indexing 1,Add 
        //  return solveMem(s,p ,s.length(), p.length(),dp);

        // return solveTab(s, p);
        return solveSpaceOptimization(s,p);
    }
};
