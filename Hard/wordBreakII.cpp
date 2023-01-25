Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
//CODE

class Solution {
public:
    unordered_set<string> st;
    void solve(int ind,string str,string s,vector<string>& ans){
	  //base case
        if(ind==s.length()){
            ans.push_back(str);
            return ;
        }
		
        string temp = ""; //temporary string for finding string in dictionary from ind
		
        for(int i=ind;i<s.length();i++){
            temp += s[i];
            if(st.count(temp)){
                string k = str;  //By initialising str to k then we don't need to do backtrack
                if(str.size()!=0) k += " "; // Edge Case 
                k += temp;
                solve(i+1,k,s,ans);
            }
        }
    }
	
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto i:wordDict) st.insert(i);
        int ind=0;
        vector<string> ans;
        string str = "";
        solve(ind,str,s,ans);
        return ans;                  
    }
};
