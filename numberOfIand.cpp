200. Number of Islands
Medium
18.5K
410
Companies
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"], // 1,1,1,1
  ["1","1","0","1","0"],// 1,1
  ["1","1","0","0","0"],// 1,1  all connected to each others
  ["0","0","0","0","0"]
]
Output: 1 // so
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
  
  

class Solution {
public:

// Note :
 /* 2 condition
  1. if meet '1' then findout the adjucent of all '1' .
  2. then make '0' instead of '1'.
  */
    void dfs(vector<vector<char>>&grid,int i,int j){
        if(i>grid.size()-1 || j>grid[0].size()-1|| i<0 ||j<0 || grid[i][j]!='1'){
            return ;
        }
        grid[i][j]='0';
        dfs(grid,i+1,j); // right
        dfs(grid,i,j+1); // left 
        dfs(grid,i,j-1); // up
        dfs(grid,i-1,j); // down
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
