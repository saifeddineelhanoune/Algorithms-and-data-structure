#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct QueueNode {
    TreeNode* node;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

bool isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, TreeNode* node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

TreeNode* dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }
    QueueNode* temp = queue->front;
    TreeNode* node = temp->node;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return node;
}

char* treeNodeToString(TreeNode* root) {
    if (root == NULL) {
        return "[]";
    }
    char* output = (char*)malloc(1000 * sizeof(char));
    strcpy(output, "");
    Queue* queue = createQueue();
    enqueue(queue, root);
    while (!isQueueEmpty(queue)) {
        TreeNode* node = dequeue(queue);
        if (node == NULL) {
            strcat(output, "null, ");
            continue;
        }
        char* valStr = (char*)malloc(10 * sizeof(char));
        sprintf(valStr, "%d, ", node->val);
        strcat(output, valStr);
        free(valStr);
        enqueue(queue, node->left);
        enqueue(queue, node->right);
    }
    output[strlen(output) - 2] = '\0';
    strcat(output, "]");
    return output;
}

void trimLeftTrailingSpaces(char* input) {
    int i = 0;
    while (input[i] != '\0' && isspace(input[i])) {
        i++;
    }
    memmove(input, input + i, strlen(input) - i + 1);
}

void trimRightTrailingSpaces(char* input) {
    int i = strlen(input) - 1;
    while (i >= 0 && isspace(input[i])) {
        input[i] = '\0';
        i--;
    }
}

TreeNode* stringToTreeNode(char* input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input + 1;
    input[strlen(input) - 1] = '\0';
    if (strlen(input) == 0) {
        return NULL;
    }
    char* item = strtok(input, ",");
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = atoi(item);
    root->left = NULL;
    root->right = NULL;
    Queue* nodeQueue = createQueue();
    enqueue(nodeQueue, root);
    while (true) {
        TreeNode* node = dequeue(nodeQueue);
        if (node == NULL) {
            break;
        }
        char* leftItem = strtok(NULL, ",");
        if (leftItem != NULL) {
            TreeNode* leftNode = (TreeNode*)malloc(sizeof(TreeNode));
            leftNode->val = atoi(leftItem);
            leftNode->left = NULL;
            leftNode->right = NULL;
            node->left = leftNode;
            enqueue(nodeQueue, leftNode);
        }
        char* rightItem = strtok(NULL, ",");
        if (rightItem != NULL) {
            TreeNode* rightNode = (TreeNode*)malloc(sizeof(TreeNode));
            rightNode->val = atoi(rightItem);
            rightNode->left = NULL;
            rightNode->right = NULL;
            node->right = rightNode;
            enqueue(nodeQueue, rightNode);
        }
    }
    return root;
}

