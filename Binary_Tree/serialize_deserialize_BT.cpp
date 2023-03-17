class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str{""};
        if(!root) return str;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node==nullptr){
                str+="#,";
            }else{
                str=str+to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return nullptr;
        string str;
        stringstream ss(data);
        getline(ss,str,',');

        queue<TreeNode*> q;
        TreeNode *root = new TreeNode(stoi(str));
        q.push(root);

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            getline(ss,str,',');
            if(str=="#"){
                node->left=nullptr;
            }else{
                TreeNode *newNode = new TreeNode(stoi(str));
                node->left=newNode;
                q.push(newNode);
            }

            getline(ss,str,',');
            if(str=="#"){
                node->right=nullptr;
            }else{
                TreeNode *newNode = new TreeNode(stoi(str));
                node->right=newNode;
                q.push(newNode);
            }
        }
        return root;
    }
};
