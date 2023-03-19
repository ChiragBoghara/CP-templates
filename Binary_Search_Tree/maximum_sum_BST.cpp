class NodeValue {
public: 
    int minNode, maxNode, maxSum;
    NodeValue(int minNode, int maxNode, int maxSum)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
    }
};
class Solution {
private:
    int sum{0};
public:
    NodeValue* maxSumBSTHelper(TreeNode* root)
    {
        if(!root) return new NodeValue(INT_MAX, INT_MIN, 0);
        auto left = maxSumBSTHelper(root->left);
        auto right = maxSumBSTHelper(root->right);
        if(left->maxNode < root->val && root->val < right->minNode)
        {
            //if BT is BST
            sum = max(sum, root->val + left->maxSum + right->maxSum);
            return new NodeValue(min(root->val, left->minNode), max(root->val, right->maxNode), root->val + left->maxSum + right->maxSum);
        }
        return new NodeValue(INT_MIN, INT_MAX, left->maxSum+root->val+right->maxSum);   
    }
    int maxSumBST(TreeNode* root) {
        maxSumBSTHelper(root);
        return sum>0 ? sum : 0;
    }
};