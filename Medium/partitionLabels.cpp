763. Partition Labels
Medium
9.1K
342
Companies
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
//CODE

//time complexity O(N)
// space complexity O(1)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int pos;
        int len = 0;
        for(int i=0; i<s.length(); i++)
        {
            pos = s.find_last_of(s[i]);
            len = pos-i+1;
            for(int j=i+1; j<pos; j++)
            {
                if(s.find_last_of(s[j])>pos)
                    pos=s.find_last_of(s[j]);
                len = pos-i+1;
            }
            i = pos;
            ans.push_back(len);
        }
        return ans;

    }
};
