40. Combination Sum II
Medium
7.7K
192
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

//CODE

class Solution {
public:
   void findCombination(int index , vector<int>&arr,int target,vector<int>&output, vector<vector<int>>&ans){
       //base case
       if(target==0){
           ans.push_back(output);
           return;
       }
    
       for(int i=index;i<arr.size();i++){
           //when matched duplicate then skip it
           if( i> index && arr[i] == arr[i-1]) continue;
           //when arr ele is larger then target the come back
           if(arr[i] >target) break;
        output.push_back(arr[i]);
        // for more
        findCombination(i+1,arr,target-arr[i],output,ans);
        //backtrack
        output.pop_back();
       }

   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() ,candidates.end());
        vector<vector<int>>ans;
        vector<int>output;
        findCombination(0,candidates,target,output,ans);
        return ans;
    }
};
