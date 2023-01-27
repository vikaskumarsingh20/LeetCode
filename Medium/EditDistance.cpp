72. Edit Distance
Hard
10.9K
127
Companies
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
  //CODE 

class Solution {
public:

int solveRec(string &a , string &b , int i , int j){
    //base case
    if(i == a.length()) // i exceed og length a 
      return b.length()-j; //  remaining string return

   if(j == b.length())
     return a.length()-i;

  int ans =0 ;
  if(a[i] == b[j]){
      return solveRec(a ,b ,i +1 , j+1);
  }

  else{
      //insert
     int insertAns = 1+ solveRec(a ,b , i+1 , j);
      //delete
     int deleteAns = 1+ solveRec(a ,b , i, j+1);
      //replace
     int replaceAns = 1+ solveRec(a ,b , i+1 , j+1);
    
    ans = min(insertAns ,min(deleteAns ,replaceAns));
  }
  return ans;

}

int solveMem(string &a , string &b , int i , int j ,vector<vector<int>>&dp){
    //base case
    if(i == a.length()) // i exceed og length a 
      return b.length()-j; //  remaining string return

   if(j == b.length())
     return a.length()-i;
 
 if(dp[i][j] != -1)
   return dp[i][j];

  int ans =0 ;
  if(a[i] == b[j]){
      return solveMem(a ,b ,i +1 , j+1 ,dp);
  }

  else{
      //insert
     int insertAns = 1+ solveMem(a ,b , i+1 , j,dp);
      //delete
     int deleteAns = 1+ solveMem(a ,b , i, j+1,dp);
      //replace
     int replaceAns = 1+ solveMem(a ,b , i+1 , j+1,dp);
    
    ans = min(insertAns ,min(deleteAns ,replaceAns));
  }
  return dp[i][j] = ans;

}

int solveTab(string &a , string &b){
 
 int n = a.length();
 int m = b.length();
  vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));

  for(int j = 0 ;j<=b.length();j++){
      dp[a.length()][j]= b.length() -j;
  }
  for(int i = 0 ;i<=a.length();i++){
      dp[i][b.length()] = a.length()-i;
  }

  int ans = 0 ;

  for(int i= n-1;i>=0;i--){
      for(int j = m-1;j >=0;j--){

       if(a[i] == b[j]){
      ans =  dp[i+1][j+1];
  }

  else{
      //insert
     int insertAns = 1+  dp[i+1][j];
      //delete
     int deleteAns = 1+ dp[i][j+1];
      //replace
     int replaceAns = 1+  dp[i+1][j+1];
    
    ans = min(insertAns ,min(deleteAns ,replaceAns));
  }
    dp[i][j] = ans;

      }
  }
 return dp[0][0];

}
    int minDistance(string word1, string word2) {
        int n = word1.length();
        // return solveRec(word1 , word2 ,0 ,0);

        // vector<vector<int>> dp(word1.length(), vector<int>(word2.length(),-1));
         return solveTab( word1 , word2 );
    }
};
