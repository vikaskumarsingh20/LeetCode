link -> https://leetcode.com/problems/combinations/description/?envType=study-plan&id=algorithm-i

Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
  
  // SOLUTIONS GIVEN BELOW 
  class Solution {
public:
    void backTrack(int start,int& n,int k,vector<vector<int>> &ans,vector<int>& tmp){
        if(k==0){ //base case
            ans.push_back(tmp);
            return;
        }
        //iterate vector
        for(int i = start; i <= n; i++){
            tmp.push_back(i);
            backTrack(i+1,n,k-1,ans,tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        backTrack(1,n,k,ans,tmp);
        return ans;
    }
};
