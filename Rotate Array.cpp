Given an array, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

// 1.Approach 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
       k = k%n;  //3%7 = 3
        
        if(k>0){  // 3 > 0
            reverse(nums.begin(),nums.end()); // 7,6,5,4,3,2,1
            reverse(nums.begin(),nums.begin()+k); //  5,6,7,4,3,2,1
            reverse(nums.begin()+k,nums.end()); // 5,6,7,1,2,3,4 
        }
    }
}

// 2 approach

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         vector<int> temp = nums;
        
//         for(int i = 0; i < nums.size(); i++)
//         {
//             nums[(i + k) % nums.size()] = temp[i];  // this is formula to rotate array 
//         }
        
//     }
// };
