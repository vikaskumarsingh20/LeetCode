
149. Max Points on a Line
Hard
3.4K
403
Companies
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

 

Example 1:

https://assets.leetcode.com/uploads/2021/02/25/plane1.jpg
Input: points = [[1,1],[2,2],[3,3]]
Output: 3
Example 2:


Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
  //CODE 
  
class Solution {
public:
    int maxPoints(vector<vector<int>>& arr) {
        
        int n = arr.size();
        
        int maxi = INT_MIN;
        
        // take every point and find the slope with other points
        
        for(int i = 0; i < n; i++)
        {
            // declare a map which will store the frequency of each slope
            
            unordered_map<double, int> mp;
            
            int temp_max = 0;
            
            int x1 = arr[i][0];  //  slope formula -> m = [y2-y1]/[x2-x1]
            
            int y1 = arr[i][1];
            
            for(int j = 0; j < n; j++)
            {
                if(j == i)
                {
                    continue;
                }
                
                int x2 = arr[j][0];
                
                int y2 = arr[j][1];
                
                double nume = y2 - y1;
                
                double deno = x2 - x1;
                
                // if denominator will be zero then slope will be INT_MAX
                
                if(deno == 0)
                {
                    mp[INT_MAX]++;
                    
                    // update temp_max
                    
                    temp_max = max(temp_max, mp[INT_MAX]);
                    
                    continue;
                }
                
                // find the slope and update frequency
                
                double slope = nume / deno;
                
                mp[slope]++;
                
                temp_max = max(temp_max, mp[slope]);
            }
            
            // update maxi
            
            maxi = max(maxi, temp_max + 1);
        }
        
        return maxi;
    }
};
