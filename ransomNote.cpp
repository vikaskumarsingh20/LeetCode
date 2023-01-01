
link -> https://leetcode.com/problems/ransom-note/description/?envType=study-plan&id=data-structure-i
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
  
  //Solutions given below 
  class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // two hashtables 
        unordered_map<char, int>m,mp; 
        bool flag = false;
        for(auto i: ransomNote){
            m[i]++; //insert
        }
        for(auto i:magazine){
            mp[i]++; //insert
        }
        for(auto i: ransomNote){
            if(m[i] >mp[i]){ // if elements is more than others
                flag = true;
                  break;
            }

        }
        if(flag)
        return false;
    return true;
    }
};
