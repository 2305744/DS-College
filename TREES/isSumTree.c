typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    bool isSumTree;
    int sum;
} Result;

Result isSumTreeFast(Node* root) {
    Result res;
    if (root == NULL) {
        res.isSumTree = true;
        res.sum = 0;
        return res;
    }

    if (root->left == NULL && root->right == NULL) {
        res.isSumTree = true;
        res.sum = root->data;
        return res;
    }

    // Recursive calls to check left and right subtrees
    Result leftAns = isSumTreeFast(root->left);
    Result rightAns = isSumTreeFast(root->right);

    // Condition for current node to be a Sum Tree node
    bool condition = root->data == leftAns.sum + rightAns.sum;

    if (leftAns.isSumTree && rightAns.isSumTree && condition) {
        res.isSumTree = true;
        res.sum = 2 * root->data;
    } else {
        res.isSumTree = false;
    }
    return res;
}

bool isSumTree(Node* root) {
    return isSumTreeFast(root).isSumTree;
}
