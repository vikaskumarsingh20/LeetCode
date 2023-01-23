You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
  
  //CODE
  
//UPVOTE IF YOU LIKE THE SOLUTION

//MEMOISATION CODE
/* ATC, we have option to jump like fibo reached on last index
  nums   2 3 1 1 4
  index  0 1 2 3 4 
  result true
 */
class Solution {
public:
    bool findJump(int index,vector<int>& nums,int n,vector<int>& dp){
        if(index >=n-1)
           return 1;
        if(nums[index]==0) 
          return 0;
        if(dp[index]!=-1) 
          return dp[index];

        for(int i=1;i<=nums[index];i++){
            bool ans=findJump(index+i,nums,n,dp);
            if(ans) return dp[index]=1;
        }
        return dp[index]=0;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        vector<int> dp(n+1,-1);
        return findJump(0,nums,n,dp);
    }
};
