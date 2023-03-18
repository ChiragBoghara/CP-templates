
class Solution {
public:
//solution-1 o(n2)
    void insertIntoBst(TreeNode *root,int key){
        while(root){
            if(key<root->val){
                if(!root->left){
                    root->left = new TreeNode(key);
                    return;
                }
                root=root->left;
            }else if(key>root->val){
                if(!root->right){
                    root->right = new TreeNode(key);
                    return;
                }
                root=root->right;
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            insertIntoBst(root,preorder[i]);
        }
        return root;
    }
};


//solution-2
// we are given preorder and we know that if sort these values we will get inorder
//after that we can contruct bst from preorder and inorder

//solution-3
// O(n)
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }
    TreeNode* build(vector<int>& preorder,int &i,int bound){
        if(i==preorder.size() || preorder[i]>bound) return nullptr;
        TreeNode *root = new TreeNode(preorder[i++]);
        root->left=build(preorder,i,root->val);
        root->right=build(preorder,i,bound);
        return root;
    }
};