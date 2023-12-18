#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
	int					val;
	struct TreeNode		*left;
	struct TreeNode		*right;
}						TreeNode;

typedef struct QueueNode
{
	TreeNode			*node;
	struct QueueNode	*next;
}						QueueNode;

typedef struct Queue
{
	QueueNode			*front;
	QueueNode			*rear;
}						Queue;

Queue	*createQueue(void)
{
	Queue	*queue;

	queue = (Queue *)malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;
	return (queue);
}

bool	isQueueEmpty(Queue *queue)
{
	return (queue->front == NULL);
}

void	enqueue(Queue *queue, TreeNode *node)
{
	QueueNode	*newNode;

	newNode = (QueueNode *)malloc(sizeof(QueueNode));
	newNode->node = node;
	newNode->next = NULL;
	if (isQueueEmpty(queue))
	{
		queue->front = newNode;
		queue->rear = newNode;
	}
	else
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
}

TreeNode	*dequeue(Queue *queue)
{
	QueueNode	*temp;
	TreeNode	*node;

	if (isQueueEmpty(queue))
	{
		return (NULL);
	}
	temp = queue->front;
	node = temp->node;
	queue->front = queue->front->next;
	if (queue->front == NULL)
	{
		queue->rear = NULL;
	}
	free(temp);
	return (node);
}

char	*treeNodeToString(TreeNode *root)
{
	char		*output;
	Queue		*queue;
	TreeNode	*node;
	char		*valStr;

	if (root == NULL)
	{
		return ("[]");
	}
	output = (char *)malloc(1000 * sizeof(char));
	strcpy(output, "");
	queue = createQueue();
	enqueue(queue, root);
	while (!isQueueEmpty(queue))
	{
		node = dequeue(queue);
		if (node == NULL)
		{
			strcat(output, "null, ");
			continue ;
		}
		valStr = (char *)malloc(10 * sizeof(char));
		sprintf(valStr, "%d, ", node->val);
		strcat(output, valStr);
		free(valStr);
		enqueue(queue, node->left);
		enqueue(queue, node->right);
	}
	output[strlen(output) - 2] = '\0';
	strcat(output, "]");
	return (output);
}

void	trimLeftTrailingSpaces(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0' && isspace(input[i]))
	{
		i++;
	}
	memmove(input, input + i, strlen(input) - i + 1);
}

void	trimRightTrailingSpaces(char *input)
{
	int	i;

	i = strlen(input) - 1;
	while (i >= 0 && isspace(input[i]))
	{
		input[i] = '\0';
		i--;
	}
}

TreeNode	*stringToTreeNode(char *input)
{
	char		*item;
	TreeNode	*root;
	Queue		*nodeQueue;
	TreeNode	*node;
	char		*leftItem;
	TreeNode	*leftNode;
	char		*rightItem;
	TreeNode	*rightNode;

	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input + 1;
	input[strlen(input) - 1] = '\0';
	if (strlen(input) == 0)
	{
		return (NULL);
	}
	item = strtok(input, ",");
	root = (TreeNode *)malloc(sizeof(TreeNode));
	root->val = atoi(item);
	root->left = NULL;
	root->right = NULL;
	nodeQueue = createQueue();
	enqueue(nodeQueue, root);
	while (true)
	{
		node = dequeue(nodeQueue);
		if (node == NULL)
		{
			break ;
		}
		leftItem = strtok(NULL, ",");
		if (leftItem != NULL)
		{
			leftNode = (TreeNode *)malloc(sizeof(TreeNode));
			leftNode->val = atoi(leftItem);
			leftNode->left = NULL;
			leftNode->right = NULL;
			node->left = leftNode;
			enqueue(nodeQueue, leftNode);
		}
		rightItem = strtok(NULL, ",");
		if (rightItem != NULL)
		{
			rightNode = (TreeNode *)malloc(sizeof(TreeNode));
			rightNode->val = atoi(rightItem);
			rightNode->left = NULL;
			rightNode->right = NULL;
			node->right = rightNode;
			enqueue(nodeQueue, rightNode);
		}
	}
	return (root);
}
/*

typedef struct TreeNode {
   int val;
   struct TreeNode* left;
   struct TreeNode* right;
} TreeNode;


TreeNode* createTreeNode(int x) {
   TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
   node->val = x;
   node->left = NULL;
   node->right = NULL;
   return node;
}
TreeNode* stringToTreeNode(char* input) {
   // Trim the string
   while (isspace((unsigned char)*input)) {
       input++;
   }
   char* end = input + strlen(input) - 1;
   while (isspace((unsigned char)*end)) {
       end--;
   }
   *(end + 1) = '\0';

   // Split the string by commas
   char* token = strtok(input, ",");
   TreeNode* root = createTreeNode(atoi(token));
   TreeNode** nodeQueue = malloc(sizeof(TreeNode*));
   int front = 0;
   int back = 0;
   nodeQueue[back++] = root;

   while (token != NULL) {
       token = strtok(NULL, ",");
       if (token == NULL) {
           break;
       }

       trimLeftTrailingSpaces(token);
       if (strcmp(token, "null") != 0) {
           int leftNumber = atoi(token);
           nodeQueue[back++] = createTreeNode(leftNumber);
           nodeQueue[front]->left = nodeQueue[back - 1];
       }

       token = strtok(NULL, ",");
       if (token == NULL) {
           break;
       }

       trimLeftTrailingSpaces(token);
       if (strcmp(token, "null") != 0) {
           int rightNumber = atoi(token);
           nodeQueue[back++] = createTreeNode(rightNumber);
           nodeQueue[front]->right = nodeQueue[back - 1];
       }

       front++;
   }

   free(nodeQueue);
   return root;
}


void prettyPrintTree(TreeNode* node, int indent) {
   if (node == NULL) {
       printf("Empty tree\n");
       return;
   }

   prettyPrintTree(node->right, indent + 1);

   for (int i = 0; i < indent; i++) {
       printf(" ");
   }
   printf("%d\n", node->val);

   prettyPrintTree(node->left, indent + 1);
}

int main() {
   char line[1024];
   while (fgets(line, sizeof(line), stdin)) {
       TreeNode* root = stringToTreeNode(line);
       prettyPrintTree(root, 0);
   }
   return 0;
}

*/