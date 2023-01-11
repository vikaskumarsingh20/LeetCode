153. Find Minimum in Rotated Sorted Array
Medium
9.4K
450
Companies
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.
  
  //CODE

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size();
        int middle;
        while(low < high)
        {
            middle = (high-low)/2 + low;
            //1st part
            if(nums[middle] <= nums[low])
                high = middle;
            else
                low = middle;
        }
        // 2nd part
        if(low >= nums.size()-1)
            return nums.at(0);
        return nums.at(low+1);
    }
};

/*class Solution {
public:
    int findMin(vector<int>& nums) {
        //first index return
        if(nums[0] ==1) return nums[0];
        if(nums[0]<nums.back()) return nums[0];

        int l= 0 , r=nums.size()-1;
        int ans = INT_MAX;
          while(l<=r){
              int mid = (l+r)/2; 
              //one part sorted
              if(nums[mid]>=nums[0]){ 
                  l = mid+1;
              }
              // 2nd part sorted
              else{
                  ans = min(ans,nums[mid]);
                  r= mid-1;
              }
          }
          return ans;
    }
}; */
