260. Single Number III
Medium
4.7K
205
Companies
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
//CODE

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            x^=nums[i]; // will contain the xor of 2 single numbers
        }
        int cnt=0;
        while(x){
            if(x & 1)
                break;
            cnt++;
            x=x>>1; // left shifting by 1 till reach the last set bit
        }
        // cnt will contain the bit number of rightmost(1st) set bit

        // it means a number must have that bit unset and other number as set

        // now we will separate the 2 sets of array on the basis of above classification

        // xor1 will contain xor of numbers with set bit
        // xor2 will contain xor of numbers with unset bit

        
        /*
            
            nums = {2 1 2 5 1 4 4 7 3 3}

            eg: 5 ^ 7 = 3 
                1 0 1
                1 1 1
                ------
            XOR = 0 1 0 => 3
            cnt = 1 ie 1st bit is set
            so now we will divide whole into 2 parts

            1 5 1 3 3 | 2 2 7 4 4

            instead of using an extra DS, we will keep XORing while iterating
                
        */
        int xor1=0,xor2=0;
        for(int i=0;i<n;i++){
            if(nums[i] & (1<<cnt)) 
            // checking whether the cnt bit is set or not {bit mask = (1<<cnt)}
                xor1^=nums[i];
            else
                xor2^=nums[i];
        }
        vector<int> ans(2);
        ans[0]=xor1;
        ans[1]=xor2;
        return ans;
    }
};
