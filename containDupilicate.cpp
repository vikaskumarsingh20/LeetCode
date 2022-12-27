Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
  
  //SOULUTION GIVEN BELOW 
  class Solution {
public:
/*
    bool containsDuplicate(vector<int>& nums) {  //  O(N^2) time complexity
          
         for(int i =0 ;i<nums.size();i++){
             for(int j = i+1;j<nums.size();j++){
                 if(nums[i] == nums[j])
                    return true;
             }
         }
         return false;
    }
    */

     bool containsDuplicate(vector<int>& nums) {
         
          sort(nums.begin(),nums.end());

          for(int i = 1 ;i<nums.size();i++){  // o(N) time complexty
              if(nums[i] == nums[i -1])
                return true;
          }
          return false;
    }
};
