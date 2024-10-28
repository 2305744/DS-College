struct BinaryTreeNode* BinaryTreeNode {
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

void inorder(BinaryTreeNode *root, int *count) {
    // Base case
    if (root == NULL) {
        return;
    }
    
    inorder(root->left, count);
    
    // Leaf node check
    if (root->left == NULL && root->right == NULL) {
        (*count)++;
    }
    
    inorder(root->right, count);
}

int noOfLeafNodes(BinaryTreeNode *root) {
    int cnt = 0;
    inorder(root, &cnt);
    return cnt;
}
