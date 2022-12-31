link ->   https://leetcode.com/problems/permutation-in-string/submissions/868602737/
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
  
  //SOLJUTION GIVEN BELOW 
  class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> s1hash(26,0); //Total 26 char
        vector<int> s2hash(26,0);
        int s1len = s1.size();
        int s2len = s2.size();
        if(s1len>s2len) // condition ! full
            return false;
        
        int left=0,right=0;
        while(right<s1len)
        {
            s1hash[s1[right]-'a'] +=1;
            s2hash[s2[right]-'a'] +=1;
            right +=1;
        }
        right -=1;  // to point right to the end of the window
        while(right<s2len)
        {
            if(s1hash==s2hash)
                return true;
            right+=1;
            if(right!=s2len)
                s2hash[s2[right]-'a'] +=1;
            s2hash[s2[left]-'a'] -=1;
            left +=1;
        }
        return false;
    }
};
