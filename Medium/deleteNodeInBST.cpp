450. Delete Node in a BST
Medium
7K
178
Companies
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []
//code
 //METHOD 1

Notes-
     1.here total three cases given below which are used to solve this pblm.
     2.case1 just remove which haven't child.
     3.case2 if node have one child then replace it with its child.
     4.two children have then remove it.

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root) 
         //We frecursively call the function until we find the target node
            if(key < root->val)
             root->left = deleteNode(root->left, key);     
            else if(key > root->val) 
               root->right = deleteNode(root->right, key); 

            else{  //No child condition
                if(!root->left && !root->right) return NULL; 
                  //One child contion -> replace the node with it's child
                if (!root->left || !root->right)
                    return root->left ? root->left : root->right;    
					                                                //Two child condition   
                TreeNode* temp = root->left;                        //(or) TreeNode *temp = root->right;
                while(temp->right != NULL) temp = temp->right;     //      while(temp->left != NULL) temp = temp->left;
                root->val = temp->val;                            //       root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);  //        root->right = deleteNode(root->right, temp);		
            }
        return root;
    }   
};

//  MATHOD 2

Notes-
     1.first find the getnode.
     2.if found the node then shift to the subtree to rightmost node.
     3.store in curr then then delete it.
     
        Time Complexity:O(H) where h is height of tree
        Space Complexity:(1)
 
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
          if(root==NULL) return root;
          if(root->val==key) return getnode(root);
        
         TreeNode*curr = root;
         
         while(root!=NULL){
             
             if(root->val>key){
                 if(root->left!=NULL && root->left->val==key){
                     root->left = getnode(root->left);
                     break;
                 }
                 else{
                     root=root->left;
                 }
             }
             
             else{
                 if(root->right!=NULL && root->right->val==key){
                     root->right = getnode(root->right);
                     break;
                 }
                 else{
                     root=root->right;
                 }
             }
         }
        return curr;
    }
    
    TreeNode* getnode(TreeNode* root){
        if(root->left==NULL){
            return root->right;
        }
        if(root->right==NULL){
            return root->left;
        }
        
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = getRightmostofleft(root->left);
        lastRight -> right = rightChild;
        
        return root->left;
        
    }
    
    TreeNode* getRightmostofleft(TreeNode* root){
        if(root->right==NULL){
            return root;
        }
        return getRightmostofleft(root->right);
    }
};
