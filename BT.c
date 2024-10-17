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
struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct Node** array;
};
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (struct Node**)malloc(queue->capacity * sizeof(struct Node*));
    return queue;
}
int isFull(struct Queue* queue) { return (queue->size == queue->capacity); }
int isEmpty(struct Queue* queue) { return (queue->size == 0); }
void enqueue(struct Queue* queue, struct Node* item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}
struct Node* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) return NULL;
    struct Node* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;
    struct Queue* queue = createQueue(1000);  
    enqueue(queue, root);
    while (!isEmpty(queue)) {
        int nodeCount = queue->size; 
        while (nodeCount > 0) {
            struct Node* node = dequeue(queue);
            printf("%d ", node->data);
            if (node->left != NULL)
                enqueue(queue, node->left);
            if (node->right != NULL)
                enqueue(queue, node->right);
            nodeCount--;
        }
        printf("\n");
    }
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
    printf("Level Order Traversal:\n");
    levelOrderTraversal(root);
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
