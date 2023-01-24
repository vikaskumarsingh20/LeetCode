5. Longest Palindromic Substring
Medium
23.6K
1.4K
Companies
Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
  //CODE

class Solution {
public:
	int maxlen=1,start=0;
	bool Meomrization(int i,int j,string& s,vector<vector<int>>& dp){
        //base case
		if(i>=j)
          return true;

		if(dp[i][j]!=-1)
           return dp[i][j];

           //checking palindrome string
		bool flag=false;
		if(s[i]==s[j]) 
          flag=Meomrization(i+1,j-1,s,dp);
  
		if(flag){
			if(j-i+1>maxlen){
				maxlen=j-i+1;
				start=i;
			}
		}
		return dp[i][j]=flag;
	}

	string longestPalindrome(string s) {
		int n = s.size();
		vector<vector<int>> dp(n,vector<int>(n,-1));
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++) 
            bool temp=Meomrization(i,j,s,dp);
		}
		return s.substr(start,maxlen);
	}
};
