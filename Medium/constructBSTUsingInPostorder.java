Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]


          inorder = [9,3,15,20,7]
        postorder = [9,15,7,20,3]

Notes:
     1.last element of postorder is rootnode.
     2.see this element in inorder and divide into two part left and right part then start construct tree.
     3.find the length of left part and right part in inorder.
     4.then call the function for left right in inorder as well as postorder.
    
    Time Complexity: O(N) linear
    Space Complexity:O(N) n no. of nodes

//code
class Solution {

        private TreeNode helper(int[] inorder, int[] postorder, int inStart, int inEnd, int postStart, int postEnd)     {
        if (inStart > inEnd) {
            return null;
        }
        
        int rootVal = postorder[postEnd];
        TreeNode root = new TreeNode(rootVal);
        
        // find rootnode
        int rootIndex = inStart;
        for (; rootIndex <= inEnd; rootIndex++) {
            if (inorder[rootIndex] == rootVal) {
                break;
            }
        }
        //length of inorder and postorder
        int leftTreeSize = rootIndex - inStart;
        int rightTreeSize = inEnd - rootIndex;
        
        //funtion calls
        root.left = helper(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + leftTreeSize - 1);
        root.right = helper(inorder, postorder, rootIndex + 1, inEnd, postEnd - rightTreeSize, postEnd - 1);
        return root;
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int len = inorder.length;
        return helper(inorder, postorder, 0, len - 1, 0, len - 1);
    }
}
