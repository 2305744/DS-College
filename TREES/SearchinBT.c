typedef struct TreeNode {
    int val;               
    struct TreeNode* left;  
    struct TreeNode* right; 
} TreeNode;

TreeNode* searchBST(TreeNode* root, int val) {
    // Base case: if the current node is NULL, return NULL
    if (root == NULL) {
        return NULL;
    }
    
    // If the current node's value matches the search value, return the node
    if (root->val == val) {
        return root;
    }
    
    // If the current node's value is greater than the search value, search in the left subtree
    if (root->val > val) {
        return searchBST(root->left, val);
    }
    
    // Otherwise, search in the right subtree
    return searchBST(root->right, val);
}
