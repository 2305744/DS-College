typedef struct TreeNode {
    int val;                
    struct TreeNode* left;  
    struct TreeNode* right; 
} TreeNode;

int maxDepth(TreeNode* root) {
    // Base case: if the tree is empty, return 0
    if (root == NULL) {
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return (left > right ? left : right) + 1;
}
