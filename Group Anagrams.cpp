Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]


code****
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         int size = strs.size();
        
        map<string, vector<string>> mp;
        
        for(auto str : strs){
            
            string temp = str;    //this step for the copy and not lost the original string..
            sort(temp.begin(), temp.end());
            mp[temp].push_back(str);
        }
        
        vector<vector<string>> ans;
        
        for(auto i : mp){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};
