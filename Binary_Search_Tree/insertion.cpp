class Solution {
public:

    //always think iteratively or maintaing range in all bst solutions
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //in BST questions try to think iteratively
        TreeNode *res = root;
        TreeNode *newNode = new TreeNode(val);
        //just find where it can be and just insert
        if(!root) return newNode;
        while(root){
            if(val<root->val){
                if(!root->left){
                    root->left = newNode;
                    break;
                }else{
                    root=root->left;
                }
            }else{
                if(!root->right){
                    root->right = newNode;
                    break;
                }else{
                    root=root->right;
                }
            }
        }
        return res;
    }
};
