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
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1; // Add 1 for the current node
}

// Function to calculate the diameter of the binary tree
DiameterInfo diameter(TreeNode* root) {
    DiameterInfo info;
    if (root == NULL) {
        info.diameter = 0;
        info.depth = 0;
        return info;
    }

    // Recursive calls to left and right subtrees
    DiameterInfo leftInfo = diameter(root->left);
    DiameterInfo rightInfo = diameter(root->right);

    // Calculate the three cases for diameter
    int case1 = leftInfo.diameter;              // Diameter from the left subtree
    int case2 = rightInfo.diameter;             // Diameter from the right subtree
    int case3 = leftInfo.depth + rightInfo.depth; // Diameter through the root

    // The maximum diameter found
    info.diameter = (case1 > case2 ? case1 : case2) > case3 ? (case1 > case2 ? case1 : case2) : case3;

    // Current depth of the tree
    info.depth = (leftInfo.depth > rightInfo.depth ? leftInfo.depth : rightInfo.depth) + 1;

    return info;
}

int diameterOfBinaryTree(TreeNode* root) {
    if (root == NULL) return 0;
    return diameter(root).diameter;
}
