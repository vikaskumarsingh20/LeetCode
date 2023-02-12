Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
//CODE


Brute force Approach
                    Time:O(N)
                    space:O(N)

       [  vector<int> leftProduct,rightProduct;
        leftProduct[0]=nums[0];
        for(int i=1;i<n;i++){
            leftProduct[i]=nums[i]* leftPriduct[i-1];
        }
        rightProduct[0]=nums.back();
        for(int i=n-2;i>=0;i--{
	    rightProduct[i]=nums[i]* rightPriduct[i+1];

]

class Solution {
public:
      // time: O(N)
      //space:O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>output;
        if(n<1){ // -ve
            return output;
        }
        int product=1; // product of all elements
        for(int i=0;i<n;i++){
            product*=nums[i];
            output.push_back(product);
        }
        //traverse from right array and update output array
        product=1;
        for(int i=n-1;i>0;i--){ // except self and move forward
            output[i]=output[i-1]*product;
            product*=nums[i];
        }
        output[0]=product;
        return output;
    }
};
