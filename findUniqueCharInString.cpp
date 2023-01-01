link -> https://leetcode.com/problems/first-unique-character-in-a-string/submissions/869102537/?envType=study-plan&id=data-structure-i
class Solution {
public:
    int firstUniqChar(string s) {
        
        //HashTable to store unique char 
        unordered_map<char ,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;  // take input in hashtable 
        }
        for(int i=0;i<s.length();i++){
            if(mp[s[i]] ==1) // if char is matched from hashtable then simply return index
             return i;
        }
        return -1; // not found then return -1
    }
};
