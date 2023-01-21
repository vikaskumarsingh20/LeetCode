47. Permutations II
Medium
7K
126
Companies
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

//CODE

class Solution {
    private:
    void solve(vector<int>nums,  set<vector<int>>&res, int index){
        // set -> unique element stores
        if(index>=nums.size()){
            res.insert(nums);
            return;
        }
        // just like permutation 
        for(int i = index;i<nums.size();i++){
            // swapping indexing 
            swap(nums[index],nums[i]);
            // func call
            solve(nums,res,index+1);
            //then again swap
            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>res;
        vector<vector<int>>ans;
        solve(nums,res, 0);
        for(auto x:res){
            ans.push_back(x);
        }
    return ans;
    }
};
