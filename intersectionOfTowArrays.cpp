350. Intersection of Two Arrays II
Easy
5.8K
811
Companies
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
  
  ///solution given below 
  class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map; // Hash table
        vector<int>result;
        for(int i=0;i<nums1.size();i++)
        {
            map[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++ )
        {
            if(map[nums2[i]]>0)
                result.push_back(nums2[i]);
                map[nums2[i]]--;
        }
        return result;
    }
};
