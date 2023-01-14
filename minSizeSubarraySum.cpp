209. Minimum Size Subarray Sum
Medium
8.5K
236
Companies
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 
  
  //CODE

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum = 0;            //Current Sum
        int left = 0;           //left ptr
        int right = 0;          //right ptr
        int shortest = INT_MAX; //shortest window with Sum>=Target
        
        //Variable Size sliding window: 2-pointer
        while(right<n){
            sum += nums[right];//Add current element to Sum
            
            if(sum >= target){//Check if currentSum >= Target
                //Skip all left elements till sum < target (to find the smallest window)
                while(sum>=target){
                    sum -= nums[left];
                    left++;
                }
                shortest = min(shortest,right-left+2);//Update smallest window size
            }
            right++;
        }
        return shortest==INT_MAX?0:shortest;
    }
};
