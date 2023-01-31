136. Single Number
Easy
12.8K
492
Companies
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
  //CODE

class Solution {
public:
  /* 
  Time Complexity = O(N) linear
  Space Complexity = O(1)
  */
    int singleNumber(vector<int>& nums) {
         // storing the ans
         int ans =0;
         // const interate 32 bits
        for(int i=0;i<32;i++){
            int sum = 0;
            // counts the one ,interate over the array
            for(int j=0;j<nums.size();j++){
                if((nums[j]>>i & 1)== 1)
                   sum++;
            }
            // grouping 
            sum%=2;
            // not equal
            if(sum != 0)
            // update ans
             ans |= sum<<i;
        }
        return ans;
    }
};
