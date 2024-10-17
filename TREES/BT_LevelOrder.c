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
struct Queue {
    int front, rear, size;
    int capacity;
    struct Node** arr;  
};
struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->arr = (struct Node**)malloc(q->capacity * sizeof(struct Node*)); 
    return q;
}
int isFull(struct Queue* q) {
    return (q->size == q->capacity);
}
int isEmpty(struct Queue* q) {
    return (q->size == 0);
}
void enqueue(struct Queue* q, struct Node* item) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = item;
    q->size = q->size + 1;
}
struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }
    struct Node* item = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;
    return item;
}
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;
    struct Queue* q = createQueue(1000);
    enqueue(q, root);
    while (!isEmpty(q)) {
        int nodeCount = q->size;
        while(nodeCount > 0){
            struct Node* node = dequeue(q);
            printf("%d ", node->data);
            if (node->left != NULL)
                enqueue(q, node->left);
            if (node->right != NULL)
                enqueue(q, node->right);
            nodeCount--;
        }
        printf("\n");
    }
    free(q->arr);
    free(q);
}
struct Node* buildFromLevelOrder() {
    struct Queue* q = createQueue(1000);
    int data;
    printf("Enter data for root: ");
    scanf("%d", &data);
    struct Node* root = createNode(data);
    enqueue(q, root);
    while (!isEmpty(q)) {
        struct Node* temp = dequeue(q);
        printf("Enter left node for %d : ", temp->data);
        int leftData;
        scanf("%d", &leftData);
        if (leftData != -1) {
            temp->left = createNode(leftData);
            enqueue(q, temp->left);
        }
        printf("Enter right node for %d : ", temp->data);
        int rightData;
        scanf("%d", &rightData);
        if (rightData != -1) {
            temp->right = createNode(rightData);
            enqueue(q, temp->right);
        }
    }
    free(q->arr);
    free(q);
    return root; 
}
int main() {
    struct Node* root = NULL;
    root = buildFromLevelOrder(); 
    printf("Level Order Traversal:\n");
    levelOrderTraversal(root);
    return 0;
}
