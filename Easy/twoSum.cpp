Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
//CODE

// Approach 1 with t.c o(n^2)
class Solution {
    public int[] twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        for(int i=0; i<nums.length-1; i++){  //1sr ptr
            for(int j=i+1; j<nums.length; j++){ // 2nd ptr
                if(nums[i] + nums[j] == target){
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }
        return ans;
    }
}

// Approach 2 t.c o(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
    unordered_map<int,int> m;v// hashmap
    
    for(int i =0;i<nums.size();i++){
       int sum = target - nums[i];
        
        if(m.count(sum)){
            ans.push_back(m[sum]);
            ans.push_back(i);
			return ans;
        }else{
            m[nums[i]] = i;
        }
        
    }
    return ans;
    }
};
