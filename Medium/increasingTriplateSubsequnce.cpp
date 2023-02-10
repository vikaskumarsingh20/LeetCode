
334. Increasing Triplet Subsequence
Medium
6.2K
269
Companies
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
  
//METHOD 1 BRUTE FORCE
// brute force O(N^3)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
         int n = nums.size();
         for(int i=0;i<n;i++){
			 for(int j=i;j<n;j++){
                 for(int k=j;k<n;k++){
                     if(nums[k] > nums[j] && nums[j] > nums[i]){
                         return true;
                     }
                 }
             }
         }
         return false;
    }
};

//METHOD 2  BETTER SOLUTION
		// T.C. -> O(N) 
   // S.C. -> O(N)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

         int n = nums.size();
         vector<int> lmin(n);
         vector<int> rmax(n);
        
         lmin[0] = nums[0];
         for(int i=1;i<n;i++){ // Fill left min array
             lmin[i] = min(lmin[i-1],nums[i]);
         }
        
         rmax[n-1] = nums[n-1];
         for(int i=n-2;i>=0;i--){ // fill right max array
             rmax[i] = max(rmax[i+1],nums[i]);
         }
        
         for(int i=1;i<n;i++){
               // Check for an element nums[i] such that it satisfies below condition
             if(lmin[i-1] < nums[i] && nums[i] < rmax[i]){
                 return true;
             }
         }
         return false;
	 }
};
//MATHOD 3 OPTIMAL SOLLUTION
		// T.C. -> O(N)
   // S.C. -> O(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int n = nums.size();
        int small = INT_MAX, large = INT_MAX;
        for(int i=0;i<n;i++){

            if(nums[i] <= small){ // store the smallest number
                small = nums[i];
            }
            
            else if(nums[i] <= large){ // store the 2nd smallest no.
                large = nums[i];
            }
            
            else{ // If a no. bigger than large is present
                return true;
            }
        }
        return false;
	}
};
