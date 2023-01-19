Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
  // SOLUTIONS

Approach
Start the BFs from the cell (0,0)
Check the 8 directionally adjancent cells,if there are not visited take it into the queue.
The first time we encountered the cell (n-1,n-1) is the minium distance.
IF we don't encounter the cell (n-1,n-1) then there is no clear path.
class Solution {
private : 
    typedef vector<vector<int>> vvi; 
    int xx[8] = {0,0,-1,1,-1,-1,1,1};
    int yy[8] = {1,-1,0,0,-1,1,1,-1}; 
    
  
    
    int shortestPathBFs(vvi &grid,int n)
    {
        queue<pair<int,int>> q;
        q.push({0,0});
        //distance matrix keeps track of the minimum distance from the cell (0,0) to cell(i,j)
        vector<vector<int>> distance(n,vector<int>(n,0));
        //intial distance of cell (0,0) is 1
        distance[0][0] = 1;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            int dist = distance[x][y];
            q.pop();
            //checking the 8 directionally adjacent cells
            for(int i=0; i<8; i++)
            {
                int nx = x + xx[i],ny = y + yy[i];
            //IF the adjacent cell is valid,and it is zero and it is not yet visited,then take into queue.
                if(nx >= 0 && nx < n && ny >=0 && ny < n && !grid[nx][ny] && !distance[nx][ny])
                {  
                    /*If the last cell (n-1,n-1) is visited for the first time,then it is the minimum
                    distance so return the distance.*/
                    if(nx == n-1 && ny == n-1)
                      return dist+1;
                    /*updating the distance of current adjacent cell */
                    distance[nx][ny] = dist+1;
                    q.push({nx,ny});
                }
            }
        }
        /*Returning -1 as the cell (n-1,n-1) cannot be reached*/
        return -1;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0])
           return -1;
        if(n == 1) return 1;
        return shortestPathBFs(grid,n);
    }
};   

//DFS
Complexity
N is the no of cells in the grid.

Time complexity: O(8N)
For each cell there are 8 adjacent cells need to be checked. And the each cell is visited once or twice.

Space complexity: O(N)
Space for the distance matrix and the queue.

DFs Solution
Verdict : Time Limit Exceeded.

TLE occurs because in DFs we explores all possible clear paths and takes the path with minimum distance.
For finding the all paths, the cell needs to be visited multiple times, so it causes TLE.

class Solution {
private : 
    typedef vector<vector<int>> vvi; 
    int xx[8] = {0,0,-1,1,-1,-1,1,1};
    int yy[8] = {1,-1,0,0,-1,1,1,-1}; 
    
    int shortestPathDFs(int x,int y, vvi &grid,vvi &visited,int n, int cells)
    {
         if(x == n-1 && y == n-1)
           return cells;
         int minCells = INT_MAX;
         visited[x][y] = 1;
         for(int i=0; i<8; i++)
         {
             int nx = x + xx[i], ny = y + yy[i];
             if(nx < n && nx >= 0 && ny < n && ny >=0 && !grid[nx][ny] && !visited[nx][ny]) 
                  minCells = min(minCells, shortestPathDFs(nx,ny,grid,visited,n,cells+1));
         }
         visited[x][y] = 0;
         return minCells;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0])
           return -1;
        if(n == 1) return 1;
        vector<vector<int>> visited(n,vector<int>(n,0)); 
        int ans = shortestPathDFs(0,0,grid,visited,n,1);
        return ans != INT_MAX ? ans : -1;
    }
};   
