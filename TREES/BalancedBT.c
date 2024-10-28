typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    int diameter; 
    int depth; 
} DiameterInfo;

int maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return (left > right ? left : right) + 1;
}

// Function to calculate the diameter of the tree
DiameterInfo diameter(TreeNode* root) {
    DiameterInfo info;
    if (root == NULL) {
        info.diameter = 0;
        info.depth = 0;
        return info;
    }

    DiameterInfo leftInfo = diameter(root->left);
    DiameterInfo rightInfo = diameter(root->right);

    int case1 = leftInfo.diameter; // Diameter from the left subtree
    int case2 = rightInfo.diameter; // Diameter from the right subtree
    int case3 = leftInfo.depth + rightInfo.depth; // Diameter through the root

    // Maximum diameter found
    info.diameter = (case1 > case2 ? case1 : case2) > case3 ? (case1 > case2 ? case1 : case2) : case3;

    // Current depth of the tree
    info.depth = (leftInfo.depth > rightInfo.depth ? leftInfo.depth : rightInfo.depth) + 1;

    return info;
}

// Function to return the diameter of the binary tree
int diameterOfBinaryTree(TreeNode* root) {
    if (root == NULL) return 0;
    return diameter(root).diameter;
}

void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
