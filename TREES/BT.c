#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* buildTree(struct Node* root){
    int data;
    printf("Enter the data: \n");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    root = createNode(data);
    printf("Enter data for inserting in left of %d:\n", data);
    root->left = buildTree(root->left);
    printf("Enter data for inserting in right of %d:\n", data);
    root->right = buildTree(root->right);
    return root;
}
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);   
    printf("%d ", root->data);      
    inorderTraversal(root->right);  
}
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);      
    preorderTraversal(root->left);  
    preorderTraversal(root->right); 
}
void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);   
    postorderTraversal(root->right);  
    printf("%d ", root->data);    
}
int main() {
    struct Node* root = NULL;
    root = buildTree(root);
    printf("Inorder Traversal of the binary tree is: ");
    inorderTraversal(root); 
    printf("\n");
    printf("Preorder Traversal of the binary tree is: ");
    preorderTraversal(root);  
    printf("\n");
    printf("Postorder Traversal of the binary tree is: ");
    postorderTraversal(root); 
    printf("\n");
    return 0;
}
