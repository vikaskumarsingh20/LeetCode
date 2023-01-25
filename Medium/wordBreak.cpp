Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
  //CODE
  
class Solution {
public: 
     //TLE by recursion
    bool solveRec(int i , string s,set<string>&wordDict){
        //reached till end
        if(i ==s.size())
         return true;
        string temp;
        for(int j =i;j<s.size();j++){
            temp +=s[j];
            //string is present
        if(wordDict.find(temp) != wordDict.end()){
            if(solveRec(j+1 , s,wordDict))
            return true;
          }
       }
      return  false;
    }

         int dp[301]; //constraints given
        bool solveMem(int i , string s,set<string>&wordDict ,vector<int>&dp){
        //reached till end
        if(i ==s.size())
         return true;
         if(dp[i] != -1)
           return dp[i];
        string temp;
        for(int j =i;j<s.size();j++){
            temp +=s[j];
            //string is present
        if(wordDict.find(temp) != wordDict.end()){
            if(solveMem(j+1 , s,wordDict,dp))
            return dp[i]= true;
          }
       }
      return  dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        vector<int>dp(s.size() ,-1);
        for(auto a:wordDict) st.insert(a);
        // return solveRec(0,s,st);
        return solveMem(0,s,st,dp);
        
    }
};
