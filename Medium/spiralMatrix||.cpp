59. Spiral Matrix II
Medium
4.6K
203
Companies
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
//CODE


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         vector<vector<int>>matrix(n, vector<int>(n,0));
        int top=0, down =n-1,left =0,right = n-1;
         int val =1;
         // in range
        while(val <=n*n){
            // left to right move
            for(int i=left;i<=right;i++)
                matrix[top][i] = val++;
                top+=1;
            // top to down move
           for(int i = top;i<=down;i++)
               matrix[i][right] =val++;
               right-=1;
            //right to left move
           for(int i = right;i>=left;i--)
               matrix[down][i]=val++;
               down-=1;
           // down to top move
           for(int i = down;i>=top;i--)
               matrix[i][left] = val++;
                  left+=1;
        }
        return matrix;
    }
};
