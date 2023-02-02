56. Merge Intervals
Medium
17.9K
616
Companies
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.\
//CODE

class Solution {
public:
/* time complexity O(nlogn)
   space complexity O(N)
   */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // for storing the final result
        vector<vector<int>> res;
        // no elements in arrary 
        if(intervals.size()==0){
            return res;
        }      
        // lemda function , sorted 1st,declare Arrays
        sort(intervals.begin(), intervals.end(),[](vector<int> &a, vector<int> &b){
            // starting ele is less the to another array
            return a[0] < b[0];
        });
        //  push curr 1st interval elements  
        vector<int> curr=intervals[0];
        // interate all array
        for(int i=1;i<intervals.size();i++){
            //  curr.end < ith.start no overlap b/w them
            if(curr[1]<intervals[i][0]){
                // push into array
                res.push_back(curr);
                //updates 
                curr=intervals[i];
            }
            else{
                // merging -> max(curr.start,ith.end)
                curr[1]=max(curr[1], intervals[i][1]);
            }
        }
        
        res.push_back(curr);
        return res;
    }
};
