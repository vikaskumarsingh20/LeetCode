79. Word Search
Medium
12.6K
505
Companies
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

  //CODE
class Solution {
public:
bool dfs(int i,int j,int count,vector<vector<char>>& board,string word)
{
    //base case
    if(count==word.size())  return true;

    // Invalid Move
    if(i>=board.size() || j>=board[0].size() || i<0 || j<0 || word[count]!=board[i][j])
         return false;

    //store the character to make the change reversible

    char a=board[i][j];
    board[i][j]='.';

     //4 directions
    bool res=dfs(i-1,j,count+1,board,word) ||
             dfs(i+1,j,count+1,board,word) ||
             dfs(i,j-1,count+1,board,word) || 
             dfs(i,j+1,count+1,board,word);

        board[i][j]=a;
 return res;

}
    bool exist(vector<vector<char>>& board, string word) {
        
        //using the dfs traversal to check whether word exist in the string or not
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {   //matched
                if(board[i][j]==word[0] && dfs(i,j,0,board,word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
