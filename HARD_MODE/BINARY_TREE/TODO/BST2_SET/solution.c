#include <stdio.h>
#include <stdlib.h>
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

TreeNode* newNode(int value) {
  TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
  temp->val = value;
  temp->left = temp->right = NULL;
  return temp;
}

void enqueue(QueueNode** head, TreeNode* node) {
  QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
  temp->node = node;
  temp->next = *head;
  *head = temp;
}

TreeNode* dequeue(QueueNode** head) {
  if (*head == NULL) return NULL;
  QueueNode* temp = *head;
  *head = (*head)->next;
  TreeNode* node = temp->node;
  free(temp);
  return node;
}

TreeNode* insertNode(TreeNode* node, int value) {
  if (node == NULL) {
      return newNode(value);
  }
  if (value < node->val) {
      node->left = insertNode(node->left, value);
  } else if (value > node->val) {
      node->right = insertNode(node->right, value);
  }
  return node;
}

void printTree(TreeNode* root) {
  if (root == NULL) return;
  QueueNode* queue = NULL;
  enqueue(&queue, root);
  while (queue != NULL) {
      TreeNode* node = dequeue(&queue);
      printf("%d", node->val);
      if (node->left != NULL) {
          printf(" / ");
          enqueue(&queue, node->left);
      }
      if (node->right != NULL) {
          printf(" \\ ");
          enqueue(&queue, node->right);
      }
      printf("\n");
  }
}

int main() {
  int arr[] = {15, 3, 16, 2, 1, 4, 19, 17, 28, 31, 12, 14, 11, 0};
  int n = sizeof(arr) / sizeof(arr[0]);
  TreeNode* root = NULL;
  for (int i = 0; i < n; i++) {
      root = insertNode(root, arr[i]);
  }
  printTree(root);
  return 0;
}