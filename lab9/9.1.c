#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int value) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct Node* insertNode(struct Node* root, int value) {
	if (root == NULL) {
		return createNode(value);
	}
	if (value < root->data) {
		root->left = insertNode(root->left, value);
	} else if (value > root->data) {
		root->right = insertNode(root->right, value);
	}
	return root;
}

void preorder(struct Node* root) {
	if (root == NULL) {
		return;
	}
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct Node* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void postorder(struct Node* root) {
	if (root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}

int searchNode(struct Node* root, int key) {
	while (root != NULL) {
		if (key == root->data) {
			return 1;
		}
		if (key < root->data) {
			root = root->left;
		} else {
			root = root->right;
		}
	}
	return 0;
}

void freeTree(struct Node* root) {
	if (root == NULL) {
		return;
	}
	freeTree(root->left);
	freeTree(root->right);
	free(root);
}

int main() {
	struct Node* root = NULL;
	int n;
	printf("Enter number of nodes: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid input\n");
		return 0;
	}
	printf("Enter elements of BST: ");
	for (int i = 0; i < n; i++) {
		int value;
		if (scanf("%d", &value) != 1) {
			printf("Invalid input\n");
			freeTree(root);
			return 0;
		}
		root = insertNode(root, value);
	}
	printf("BST Created\n\n");
	int choice;
	while (1) {
		printf("MAIN MENU\n");
		printf("1. Preorder\n");
		printf("2. Postorder\n");
		printf("3. Inorder\n");
		printf("4. Search\n");
		printf("5. Exit\n");
		printf("Enter option: ");
		if (scanf("%d", &choice) != 1) {
			printf("Invalid option\n");
			break;
		}
		if (choice == 1) {
			printf("Preorder: ");
			preorder(root);
			printf("\n");
		} else if (choice == 2) {
			printf("Postorder: ");
			postorder(root);
			printf("\n");
		} else if (choice == 3) {
			printf("Inorder: ");
			inorder(root);
			printf("\n");
		} else if (choice == 4) {
			int key;
			printf("Enter element to search: ");
			if (scanf("%d", &key) != 1) {
				printf("Invalid input\n");
				break;
			}
			if (searchNode(root, key)) {
				printf("Element found\n");
			} else {
				printf("Element not found\n");
			}
		} else if (choice == 5) {
			break;
		} else {
			printf("Invalid option\n");
		}
	}
	freeTree(root);
	return 0;
}
