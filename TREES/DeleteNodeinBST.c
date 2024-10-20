int findMax(struct TreeNode *root)
{
    struct TreeNode* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->val;
}
int findMin(struct TreeNode *root)
{
    struct TreeNode* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->val;
}
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    // base case
    if(root == NULL){
        return root;
    }
    if(root->val == key){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        // 1 child
        // LEFT CHILD
        if(root->left != NULL && root->right == NULL){
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // RIGHT CHILD
        if(root->left == NULL && root->right != NULL){
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        // 2 children
        if(root->left != NULL && root->right != NULL){
            int mini = findMin(root->right);
            root->val = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    else if(root->val > key){
        // left part
        root->left = deleteNode(root->left, key);
        return root;
    }
    else{
        // right part
        root->right = deleteNode(root->right, key);
        return root;
    }
    return root;
}
