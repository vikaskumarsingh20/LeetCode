class Solution {
public:
 bool solveMem(int index , vector<int>&arr , int  N  , int target, vector<vector<int>>&dp){
       // basecase
     if(index >= N)
       return 0;
       
     if(target < 0)
       return 0;
     if(target == 0)
        return 1;
         
    if(dp[index][target] != -1)
       return dp[index][target];
       
   int include = solveMem(index +1 , arr , N ,target - arr[index] ,dp);
   int exclude = solveMem(index +1 , arr , N , target - 0 , dp);
   
   return dp[index][target] = include or exclude;
 }
 
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
          int total = 0;
      
      for(int  i =0 ;i<n;i++){
          total += nums[i];
      }
      
     if(total & 1) // if odd
        return 0;
          int target = total/2;
   
  vector<vector<int>> dp(n, vector<int>(target+1 , -1));
  return solveMem(0 , nums, n, target , dp);
    }
};
