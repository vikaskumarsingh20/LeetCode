54. Spiral Matrix
Medium
10.4K
996
Companies
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
//CODE

class Solution {
public:
   vector<int> spiralOrder(const vector<vector<int> > &A) {
    //4 ptrs at all boundary
    int Top ,Bottom ,Left , Right , direction;
    Top=0;
    Bottom = A.size()-1;
    Left=0;
    Right = A[0].size()-1;
    direction=0;
    int i;
    vector<int> ans;
     
       // THIS IS CONDIION FOR UNDERSTAND WHICH DIRECTION WANT TO MOVE 
    while(Top<=Bottom && Left<=Right)
    {
        if(direction==0)
        {
            for(i=Left;i<=Right;i++)
                ans.push_back(A[Top][i]); //top is fixed 
            Top +=1;
        }
        else if(direction==1)
        {
            for(i=Top;i<=Bottom;i++)
                ans.push_back(A[i][Right]);
            Right-=1;
        }
        else if(direction==2)
        {
            for(i=Right;i>=Left;i--)
                ans.push_back(A[Bottom][i]);
            Bottom-=1;
        }
        else if(direction==3)
        {
            for(i=Bottom;i>=Top;i--)
                ans.push_back(A[i][Left]);
            Left+=1;
        }
        
        //FOR CHECKING TO WHICH CONDTION WILL STARTS TO MOVE 
        // FOR EX - (0+1) % 4 = 1 WHICH MEANS , DIRECTION ==1 WILL EXECUTE 
        direction=(direction+1)%4;
    }
    return ans;
}
};
