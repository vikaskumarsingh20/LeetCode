link -> https://leetcode.com/problems/permutations/submissions/872019333/

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]


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
