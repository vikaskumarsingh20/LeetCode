583. Delete Operation for Two Strings
Medium
4.8K
72
Companies
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.
  //CODE
  

class Solution {
private:
    /* Time Limit Exceeded */
    int Recursion(int curr_idx1, int curr_idx2, string word1, string word2) {
      // when both matched no need to delete somethings
        if (curr_idx1 == word1.size() || curr_idx2 == word2.size()) {
            if (curr_idx1 == word1.size() && curr_idx2 == word2.size())
                return 0; //all fine
            if (curr_idx1 == word1.size())
                return word2.size() - curr_idx2;
            else
                return word1.size() - curr_idx1;
        }
        // if both same then simply iterate both strings
        if(word1[curr_idx1] == word2[curr_idx2])
            return Recursion(curr_idx1 + 1, curr_idx2 + 1, word1, word2);
        
        //remove curr_idx1
        int res1 = Recursion(curr_idx1 + 1, curr_idx2, word1, word2);
        if (res1 != INT_MAX)
            res1 = res1 + 1;
        
        //remove curr_idx2
        int res2 = Recursion(curr_idx1, curr_idx2 + 1, word1, word2);
        if (res2 != INT_MAX)
            res2 = res2 + 1;        
        // min operations
        return min(res1, res2); 
    }

        int Memorization(int curr_idx1, int curr_idx2, string word1, string word2,vector<vector<int>>&dp) {
        if (curr_idx1 == word1.size() || curr_idx2 == word2.size()) {
            if (curr_idx1 == word1.size() && curr_idx2 == word2.size())
                return 0;
            if (curr_idx1 == word1.size())
                return word2.size() - curr_idx2;
            else
                return word1.size() - curr_idx1;
        }
        if(dp[curr_idx1][curr_idx2] != -1)
              return dp[curr_idx1][curr_idx2];
        
        if(word1[curr_idx1] == word2[curr_idx2])
            return dp[curr_idx1][curr_idx2] = Memorization(curr_idx1 + 1, curr_idx2 + 1, word1, word2,dp);
        
        //remove curr_idx1
        int res1 = Memorization(curr_idx1 + 1, curr_idx2, word1, word2,dp);
        if (res1 != INT_MAX)
            res1 = res1 + 1;
        
        //remove curr_idx2
        int res2 = Memorization(curr_idx1, curr_idx2 + 1, word1, word2,dp);
        if (res2 != INT_MAX)
            res2 = res2 + 1;        
        
        return dp[curr_idx1][curr_idx2]= min(res1, res2);
    }

        /* Bottom-Up Approach : Iterative Method */
    int minDistanceBottomUp(string word1, string word2) {
        vector<vector<int>> DP(word1.size() + 1, vector<int>(word2.size() + 1, INT_MAX));
        
        for (int curr_idx1 = word1.size(); curr_idx1 >= 0; curr_idx1--)
        {
            for (int curr_idx2 = word2.size(); curr_idx2 >= 0; curr_idx2--) 
            {
                if (curr_idx1 == word1.size())
                {
                    DP[word1.size()][curr_idx2] =  word2.size() - curr_idx2;
                    
                } else if (curr_idx2== word2.size())
                {
                    DP[curr_idx1][word2.size()] =  word1.size() - curr_idx1;
                    
                }
                else if(word1[curr_idx1] == word2[curr_idx2])
                    DP[curr_idx1][curr_idx2] = DP[curr_idx1 + 1][curr_idx2 + 1];
                else
                {
                    //remove curr_idx1
                    int res1 = DP[curr_idx1 + 1][curr_idx2] == INT_MAX ? INT_MAX : DP[curr_idx1 + 1][curr_idx2] + 1;

                    //remove curr_idx2
                    int res2 = DP[curr_idx1][curr_idx2 + 1] == INT_MAX ? INT_MAX : DP[curr_idx1][curr_idx2 + 1] + 1;

                    DP[curr_idx1][curr_idx2] = min(res1, res2);
                }

                
            }
        }
        
        return DP[0][0];
    }

        /* Bottom-Up Approach with Space Optimization: Iterative Method */
    int minDistanceBottomUpSpaceOpt(string word1, string word2) {
        vector<int> next(word2.size() + 1);
        vector<int> curr(word2.size() + 1);
       
        
        for (int curr_idx1 = word1.size(); curr_idx1 >= 0; curr_idx1--)
        {
            for (int curr_idx2 = word2.size(); curr_idx2 >= 0; curr_idx2--) 
            {
                if (curr_idx1 == word1.size()) 
                    curr[curr_idx2] =  word2.size() - curr_idx2;                    
                else if (curr_idx2== word2.size())
                    curr[word2.size()] =  word1.size() - curr_idx1;
                else if(word1[curr_idx1] == word2[curr_idx2])
                    curr[curr_idx2] = next[curr_idx2 + 1];
                else
                    curr[curr_idx2] = min(next[curr_idx2] + 1, curr[curr_idx2 + 1] + 1);
            }
            next = curr;
        }
        
        return next[0];
    }
	public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
		// return Recursion(0, 0, word1, word2);
        // return Memorization(0,0,word1,word2,dp);
        // return minDistanceBottomUp(word1,word2);
        return minDistanceBottomUpSpaceOpt(word1,word2);
    }
};
