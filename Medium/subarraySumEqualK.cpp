560. Subarray Sum Equals K
Medium
17.1K
501
Companies
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
  //CODE
  // time complexity O(n)
  // space complexity O(1)

class Solution {
public:
  int subarraySum(vector<int>& nums, int k)
  {
        int n = nums.size();
        unordered_map<int, int>m;
        m[0] = 1;                            // for 0es indexs 
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i]; 
            // sum-k for finding the sum in contigous array   
            int target = sum-k;
            // if matched the simply update values
            if(m.count(target)) ans += m[target]; 
            m[sum]++;
        }
      
        return ans;
    }
};
