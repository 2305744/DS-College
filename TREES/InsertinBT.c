typedef struct TreeNode {
    int val;                
    struct TreeNode* left;  
    struct TreeNode* right; 
} TreeNode;

TreeNode* insertIntoBST(TreeNode* root, int val) {
    // Base case: if the current node is NULL, create a new node
    if (root == NULL) {
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    } else {
        root->left = insertIntoBST(root->left, val);
    }
    return root; 
}
