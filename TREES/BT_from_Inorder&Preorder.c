struct Node* Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create an index mapping array for quick lookup
void createMapping(int in[], int nodeToIndex[], int n) {
    for (int i = 0; i < n; i++) {
        nodeToIndex[in[i]] = i; // Map value to its index in inorder array
    }
}

// Recursive function to build the binary tree
Node* solve(int in[], int pre[], int *index, int inorderStart, int inorderEnd, int nodeToIndex[]) {
    // Base case
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    // Get current root element from preorder traversal
    int element = pre[*index];
    (*index)++;

    // Create the root node
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = element;
    root->left = NULL;
    root->right = NULL;

    // Find the position of this element in the inorder array
    int pos = nodeToIndex[element];

    // Recursive calls to construct the left and right subtrees
    root->left = solve(in, pre, index, inorderStart, pos - 1, nodeToIndex);
    root->right = solve(in, pre, index, pos + 1, inorderEnd, nodeToIndex);

    return root;
}

// Function to build the tree
Node* buildTree(int in[], int pre[], int n) {
    int preOrderIndex = 0;
    int nodeToIndex[1000] = {0};  

    // Create node-to-index mapping for inorder traversal
    createMapping(in, nodeToIndex, n);

    // Build the tree and return its root
    return solve(in, pre, &preOrderIndex, 0, n - 1, nodeToIndex);
}

// Function to print the tree in inorder (for testing)
void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

// Free the memory allocated for the tree
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
