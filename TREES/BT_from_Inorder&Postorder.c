struct Node* Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a mapping from each element in inorder[] to its index
void createMapping(int inorder[], int nodeToIndex[], int n) {
    for (int i = 0; i < n; i++) {
        nodeToIndex[inorder[i]] = i; // Store index of each element in inorder array
    }
}

// Recursive function to construct the binary tree from inorder and postorder traversals
Node* solve(int inorder[], int postorder[], int* index, int inorderStart, int inorderEnd, int nodeToIndex[], int n) {
    // Base case
    if (*index < 0 || inorderStart > inorderEnd) {
        return NULL;
    }

    // Get the current root element from postorder traversal
    int element = postorder[*index];
    (*index)--;

    // Create the root node
    Node* root = createNode(element);

    // Find the position of this element in the inorder array
    int pos = nodeToIndex[element];

    // Recursive calls to construct the right and left subtrees
    root->right = solve(inorder, postorder, index, pos + 1, inorderEnd, nodeToIndex, n);
    root->left = solve(inorder, postorder, index, inorderStart, pos - 1, nodeToIndex, n);

    return root;
}

// Function to build the tree given inorder and postorder traversals
Node* buildTree(int inorder[], int postorder[], int n) {
    int postOrderIndex = n - 1;
    int nodeToIndex[1000] = {0}; // Assuming elements in inorder are within range 0-999

    // Create node-to-index mapping for inorder traversal
    createMapping(inorder, nodeToIndex, n);

    // Build the tree using the helper function
    return solve(inorder, postorder, &postOrderIndex, 0, n - 1, nodeToIndex, n);
}

// Function to print the tree in inorder (for testing purposes)
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
