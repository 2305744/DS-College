struct Node* Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int findMax(struct Node* root) {
    Node* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp->data;
}

int findMin(struct Node* root) {
    Node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp->data;
}
