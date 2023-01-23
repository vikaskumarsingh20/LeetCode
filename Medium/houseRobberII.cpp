You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
  //CODE

class Solution {
public:
    int solve(vector<int> &nums, int i, int endIdx, bool allow){
        if(i >= endIdx) return 0;

        int ans;
        if(allow){
            int choose = nums[i] + solve(nums, i+1, endIdx, 0);
            int skip = 0 + solve(nums, i+1, endIdx, 1);

            ans = max(choose, skip);
        }
        else{
            ans = 0 + solve(nums, i+1, endIdx, 1);
        }

        return ans;
    }

    int solveMem(vector<int> &nums, int i, int endIdx, bool allow, vector<vector<int>> &dp){
        if(i >= endIdx) return 0;

        if(dp[i][allow] != -1){
            return dp[i][allow];
        }

        int ans;
        if(allow){
            int choose = nums[i] + solveMem(nums, i+1, endIdx, 0, dp);
            int skip = solveMem(nums, i+1, endIdx, 1, dp);

            ans = max(choose, skip);
        }
        else{
            ans = solveMem(nums, i+1, endIdx, 1, dp);
        }

        return dp[i][allow] = ans;
    }

    int solveTab(vector<int> &nums, int startIdx, int endIdx){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int i=endIdx-1; i>=startIdx; i--){
            for(int allow=0; allow<=1; allow++){
                int ans;
                if(allow){
                    int choose = nums[i] + dp[i+1][0];
                    int skip = dp[i+1][1];

                    ans = max(choose, skip);
                }
                else{
                    ans = dp[i+1][1];
                }

                dp[i][allow] = ans;
            }
        }

        return dp[startIdx][1];
    }

    int solveSO(vector<int> &nums, int startIdx, int endIdx){
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int i=endIdx-1; i>=startIdx; i--){
            for(int allow=0; allow<=1; allow++){
                int ans;
                if(allow){
                    int choose = nums[i] + next[0];
                    int skip = next[1];

                    ans = max(choose, skip);
                }
                else{
                    ans = next[1];
                }

                curr[allow] = ans;
            }
            next = curr;
        }

        return curr[1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int a = solveSO(nums, 0, n-1);
        int b = solveSO(nums, 1, n);

        return max(a,b);
    }
};
