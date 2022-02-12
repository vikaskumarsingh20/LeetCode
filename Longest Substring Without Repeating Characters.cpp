Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
  
  code*****
  class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      
        int maxLen = 0, curLen = 0;
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        
        while(r < s.length())
        {
            if(mp.find(s[r]) == mp.end())
            {
                curLen++;
                maxLen = max(maxLen, curLen);
                mp[s[r]] = r;
            }
            else
            {
                int t = l;
                l = mp[s[r]] + 1;
                curLen = r - l + 1;
                maxLen = max(maxLen, curLen);
                for(int i = t; i < l; i++)
                    mp.erase(s[i]);
                mp[s[r]] = r;
            }
            r++;
        }
        return maxLen;
    }
};
