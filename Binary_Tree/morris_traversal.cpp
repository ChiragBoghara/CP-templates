class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //morris traversal sapce - o(1)sapce o(n)time iterative
        vector<int> ans;
        TreeNode *curr = root;
        while(curr != nullptr){
            if(curr->left==nullptr){
                //if there is no left part root would be ans and i will go to rightside
                ans.push_back(curr->val);
                curr = curr->right;
            }else{
                //if there is left, make a thread and go to left
                TreeNode *prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right==nullptr){
                    prev->right = curr;
                    curr = curr->left;
                }else{
                    //it means thread is there
                    //unlink the thread
                    //prev->right==curr
                    prev->right=nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
     vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *curr=root;
        vector<int> ans;

        while(curr){
            if(curr->left==nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode *prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev = prev->right;
                }
                if(!prev->right){
                    prev->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }else{
                    //prev->right == curr;
                    prev->right=nullptr;
                    curr=curr->right;
                }
            }
        }

        return ans;
    }
};