187. Repeated DNA Sequences
Medium
2.7K
466
Companies
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        vector<string>ans;
        int n = s.size();
        // base case 
        if(n<=10){
            return ans;
        }
        // insert into hash table 
        for(int i=0; i<=n-10;i++){
            string str = s.substr(i ,10);
            mp[str]++;
        } // presented
        for(auto itr=mp.begin();itr!=mp.end(); itr++){
            if(itr->second> 1){
                ans.push_back(itr->first);
            }
        }
        return ans;
    }
};
