typedef struct TreeNode {
    int val;               
    struct TreeNode* left;  
    struct TreeNode* right; 
} TreeNode;

// Helper function to check if the binary tree is a valid BST
bool valid(TreeNode* root, long long min, long long max) {
    // Base case: An empty tree is a valid BST
    if (root == NULL) return true; 
    
    // Check the value of the current node against min and max
    if (root->val > min && root->val < max) {
        // Recursively check the left and right subtrees
        bool left = valid(root->left, min, root->val);
        bool right = valid(root->right, root->val, max);
        return left && right; 
    } else {
        return false;
    }
}

bool isValidBST(TreeNode* root) {
    return valid(root, LONG_MIN, LONG_MAX); 
}
