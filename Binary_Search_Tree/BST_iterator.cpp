class BSTIterator {
    private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        st.push(root);
        pushAllLeft(root->left);
    }
    
    int next() {
        TreeNode * node = st.top();
        st.pop();
        int data = node->val;
        pushAllLeft(node->right);
        return data;
    }
    
    bool hasNext() {
        return st.empty() ? false : true;
    }

    void pushAllLeft(TreeNode *root){
        while(root!=nullptr){
            st.push(root);
            root = root->left;
        }
    }
};