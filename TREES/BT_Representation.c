struct node* node {
    int data;
    struct node* left;
    struct node* right;
};

struct Queue* q{
    node** items;
    int front;
    int rear;
    int max_size;
};

void create_tree(node* root, int* vec, int size) {
    if (size == 0) return;
    
    root->data = vec[0];
    root->left = NULL;
    root->right = NULL;
    
    Queue* q = createQueue(size);
    enqueue(q, root);
    
    int i = 1;
    while (i < size) {
        node* temp = dequeue(q);

        // Left child creation (if exists)
        if (i < size) {
            temp->left = (node*)malloc(sizeof(node));
            temp->left->data = vec[i];
            temp->left->left = NULL;
            temp->left->right = NULL;
            enqueue(q, temp->left);
            i++;
        }

        // Right child creation (if exists)
        if (i < size) {
            temp->right = (node*)malloc(sizeof(node));
            temp->right->data = vec[i];
            temp->right->left = NULL;
            temp->right->right = NULL;
            enqueue(q, temp->right);
            i++;
        }
    }
    freeQueue(q);
}

void printLevelOrder(node* root) {
    if (root == NULL) return;

    Queue* q = createQueue(100);
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        node* temp = dequeue(q);
        printf("%d ", temp->data);

        if (temp->left != NULL) {
            enqueue(q, temp->left);
        }
        if (temp->right != NULL) {
            enqueue(q, temp->right);
        }
    }
    printf("\n");
    freeQueue(q);
}
