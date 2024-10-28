typedef struct TreeNode {
    int val;                
    struct TreeNode* left;  
    struct TreeNode* right; 
} TreeNode;

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL) {
        return false;
    }
    // Check the value of the current nodes and recursively check left and right subtrees
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    bool value = (p->val == q->val);
    return left && right && value;
}
