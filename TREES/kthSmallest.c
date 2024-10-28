typedef struct TreeNode {
    int val;                
    struct TreeNode* left;  
    struct TreeNode* right; 
} TreeNode;

int solve(TreeNode* root, int* i, int k) {
    if (root == NULL) return -1; 
  
    // LEFT
    int left = solve(root->left, i, k);
    if (left != -1) {
        return left; 
    }

    // ROOT
    (*i)++; 
    if (*i == k) {
        return root->val; 
    }

    // RIGHT
    return solve(root->right, i, k); // Continue to the right subtree
}

int kthSmallest(TreeNode* root, int k) {
    int i = 0;
    return solve(root, &i, k); 
}
