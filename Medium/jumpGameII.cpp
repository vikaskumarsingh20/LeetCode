You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
  
  //CODE

class Solution {
public:
    int Memorization(vector<int> &nums ,int n ,vector<int> &dp ){
        if(dp[n-1]!=-1)
            return dp[n-1];

        int res=INT_MAX;
        for(int i=0 ; i<=n-2; i++){
            if(nums[i]+i >= n-1){
                int sub_res = Memorization(nums , i+1,dp);
                if(sub_res!=INT_MAX){
                    res = min(res , sub_res+1);
                }
            }
        }
        return dp[n-1] = res;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        int ans = Memorization(nums ,n,dp);
        return ans==INT_MAX? -1 : ans;
    }
    
};
