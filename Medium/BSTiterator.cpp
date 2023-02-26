 Notes-
    
   1. inorder traversal i.e sorted tree.
     2.take stack DS and push elements into stack and check that if the left ele is present then simply push it.
     3.next() for right ele.
     4.repeat it 

     Time Complexity:(1) why? bcz only constant ele is pushed into stack and pop it.
     Space Complexity:(H) height of the tree

class BSTIterator {
public:

    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        partialInorder(root);
    }
    
    void partialInorder(TreeNode* root){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* top = s.top(); // top ele
        s.pop(); //pop top ele
        partialInorder(top->right);// right call
        return top->val; //simply return value
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
 
