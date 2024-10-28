typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

void inorder(TreeNode* root, int* count) {
    // Base case
    if (root == NULL) {
        return;
    }
    inorder(root->left, count);
    (*count)++; 
    inorder(root->right, count);
}

int countNodes(TreeNode* root) {
    int count = 0;
    inorder(root, &count); 
    return count;
}
