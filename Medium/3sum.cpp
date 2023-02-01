15. 3Sum
Medium
23.8K
2.2K
Companies
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
  //CODE
  

class Solution {
public:
   //TIME COMPLEXITY O(N^2)
   // SPACE COMPLEXITY O(N)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;// storing data in array
        sort(nums.begin(),nums.end()); // sorted
        set<vector<int>>unique;
        for(int i=0;i<nums.size()-2;i++) // 1st pointer
        {
            if(i>0 && nums[i]==nums[i-1])
                continue; // skip duplicate bcz we have already used it
            int j=i+1;//2nd pointer
            int k=nums.size()-1; // 3rd pointer
            while(j<k) // 2nd ptr < 3rd ptr
            {
                int sum=nums[i]+nums[j]+nums[k]; //sum 
                if(sum==0)// become 0
                {   // intert into set and incrase the 2nd pointer for more
                    unique.insert({nums[i],nums[j],nums[k]});
                    j++;
                }
                // -ve so make +ve increase 2nd ptr
                else if(sum<0)
                    j++;
                else // oterwise decrease 3rd ptr
                    k--;
            }
        }
        for(auto arr:unique)
        {
            ans.push_back(arr);
        }
        return ans;
    }
};
