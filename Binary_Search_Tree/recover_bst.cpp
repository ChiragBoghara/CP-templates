
class Solution {
public:
    void inorder(TreeNode *root,TreeNode *&prev,TreeNode *&first,TreeNode *&middle,TreeNode *&last){
        if(!root){
            return;
        }
        inorder(root->left,prev,first,middle,last);
        if(root->val < prev->val){
            //if first violation,mark these two nodes as 'first' and 'middle'
            if(first==nullptr){
                first = prev;
                middle = root;
            }else{
                //if this is second violation mark this node as last
                last = root;
            }
        }
        prev = root;
        inorder(root->right,prev,first,middle,last);
    }

    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr;
        TreeNode *middle = nullptr;
        TreeNode *last = nullptr;
        TreeNode *prev = new TreeNode(INT_MIN);
        inorder(root,prev,first,middle,last);
        if(first && last){
            swap(first->val,last->val);
        }else if(first && middle){
            swap(first->val,middle->val);
        }
    }
};