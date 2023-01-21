90. Subsets II
Medium
7.4K
207
Companies
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
//CODE

class Solution {
    public:
  set<vector<int>> st;  //set will hold unique subsets

void solve( vector<int>&nums, int i, int n, vector<int> v ){
    
    if(i==n){    //when i==n , sort the vector and insert into set
        sort(v.begin(), v.end());
        st.insert(v);  
        return;
    }
    
    v.push_back(nums[i]);  //include
    solve(nums,i+1,n,v);
    
    v.pop_back();  //exclude
    solve(nums,i+1,n,v);
}


vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    
    vector<int> v; 
    solve(nums,0,nums.size(),v);
    
    vector<vector<int>> ans;
    
    for(auto it: st){  //traverse the set and push all vectors in it into ans
        ans.push_back(it);
    }
    
    return ans;
}
};
