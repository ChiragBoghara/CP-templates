class Solution {
public:
    //search for the node to delete 
    //once found check if it its left and right child is null just return nullptr
    //if has left child but not right child return left
    //if has right child but not left child return right
    //if has both child replace root data with inorder successor node data and delete that node
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(key<root->val){
            root->left = deleteNode(root->left,key);
            return root;
        }else if(key>root->val){
            root->right = deleteNode(root->right,key);
            return root;
        }else{
            //same
            if(!root->left && !root->right){
                return nullptr;
            }else if(root->left && !root->right){
                return root->left;
            }else if(root->right && !root->left){
                return root->right;
            }else{
                TreeNode* succ=getSuccesor(root);
                root->val=succ->val;
                root->right=deleteNode(root->right,succ->val);
                return root;
            }
        }
    }

    TreeNode* getSuccesor(TreeNode *root){
        root=root->right;
        while(root!=NULL && root->left!=NULL){
            root=root->left;
        }
        return root;
    }
};