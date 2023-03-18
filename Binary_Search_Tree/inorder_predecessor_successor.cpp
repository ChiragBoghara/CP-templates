Node* findSuc(Node *root,int key){
    Node *res = nullptr;
    while(root){
        if(key>=root->key){
            root=root->right;
        }else{
            res = root;
            root=root->left;
        }
    }
    return res;
}
Node *findPre(Node *root,int key){
    Node *res = nullptr;
    while(root){
        if(key>root->key){
            res = root;
            root=root->right;
        }else{
            root=root->left;
        }
    }
    return res;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    suc = findSuc(root,key);
    pre = findPre(root,key);
}