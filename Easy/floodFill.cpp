An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.
  //CODE

class Solution {
public:
    
    // time Complexity:(N+E)
    // Space Complexity:(N)
    
    void dfs(vector<vector<int>>& image, int i, int j,int val, int newColor) {
        //all condition check when function calling
     if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] != val){ return; }

        image[i][j] = newColor;
        dfs(image,i-1,j,val,newColor);//up
        dfs(image,i+1,j,val,newColor);//down
        dfs(image,i,j-1,val,newColor);//left
        dfs(image,i,j+1,val,newColor);//right
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        //when same color matched no need to preform any call
         if(newColor == image[sr][sc]) return image;
        int val = image[sr][sc];
        dfs(image,sr,sc,val,newColor);
        return image;
    }
};
