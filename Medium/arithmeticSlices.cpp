An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [1,2,3,4]   
Output: 3  //differnece = nums[i] - nums[i-1] ,check for every elements
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
Example 2:

Input: nums = [1]
Output: 0


/*
// RECURSION - 0ms
class Solution {
public:
    int solve(vector<int> &nums, int i, int diff)
    {
        if(i == nums.size() - 1 || nums[i] + diff != nums[i + 1])
            return 0;
        
        return 1 + solve(nums, i + 1, diff);   
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        int ans = 0;
        for(int i = 0 ; i < nums.size() - 2; i++)
        {
            int diff = nums[i + 1] - nums[i];
            ans += solve(nums, i + 1, diff);
        }
        return ans;
    }
};

*/
// DP + Memoisation 
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        //out of bound
        if(nums.size() < 3)
            return 0;
        vector<int> dp(nums.size(), 0);
        int ans = 0;
        for(int i = 2 ; i < nums.size(); i++)
        {  //difference = nums[i] -nums[i-1]
            if(nums[i] -nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                dp[i] = 1 + dp[i - 1];
                ans += dp[i];
            }
        }
        return ans;
    }
};
/*
// DP + Tabulation
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        int ans = 0;
        int curr= 0;
        for(int i = 2 ; i < nums.size(); i++)
        {
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                curr++;
                ans += curr;
            }
            else
                curr = 0;
        }
        return ans;
    }
};
*/
