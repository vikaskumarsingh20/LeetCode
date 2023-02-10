435. Non-overlapping Intervals
Medium
5.5K
152
Companies
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
  //CODE

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());    //Sort all intervals in ASC order
        int count = 0;      //Count of number of intervals to be removed
        int n = intervals.size();   //No of intervals
        int left = 0;   //left interval
        int right = 1;  //right interval
        
        while(right<n)  //Unless all intervals are compared
        {         // 1,means rigth part interval ,o means left part interval
            if(intervals[left][1] <= intervals[right][0])   //Non-overlapping case
            {
                left = right;
                right+=1;
            }
            else if(intervals[left][1]<=intervals[right][1])    //Overlapping case-1 (Remove right interval)
            {
                count+=1;       //Delete right
                right+=1;
            }
            else if(intervals[left][1]>intervals[right][1])     //Overlapping case-2 (Remove left interval)
            {
                count+=1;
                left = right;
                right+=1;
            }
        }
        
        return count;
    }
};
