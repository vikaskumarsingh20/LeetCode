
986. Interval List Intersections
Medium
4.9K
96
Companies
You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

 

Example 1:


Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Example 2:

Input: firstList = [[1,3],[5,9]], secondList = []
Output: []

//CODE

class Solution {
public:
     
     // s-starting , e-ending
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        //to store answer
    vector<vector<int>>ans;
    //move two pointer
    for(int s=0, e=0; s<firstList.size() && e<secondList.size();) {
        // not intersections
        if (firstList[s][1] < secondList[e][0]){s++;}
        //not intersection
        else if (secondList[e][1] < firstList[s][0]){e++;}
        // when intersection
        else {
            // max here bcz to find the maximum common then move forword, same for min in opposite
            ans.push_back({max(firstList[s][0], secondList[e][0]), min(firstList[s][1], secondList[e][1])});
            if (firstList[s][1]<secondList[e][1]){s++;}
            else{e++;}
        }
    }
    return ans;
} 
};
