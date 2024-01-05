#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool isFullBinaryTree(TreeNode* node) {
    if (node == NULL)
        return true;
    if (node->left == NULL && node->right == NULL)
        return true;
    if (node->left != NULL && node->right != NULL)
        return isFullBinaryTree(node->left) && isFullBinaryTree(node->right);
    return false;
}

bool isCompleteBinaryTree(TreeNode* node, int index, int totalNodes) {
    if (node == NULL)
        return true;
    if (index >= totalNodes)
        return false;
    return isCompleteBinaryTree(node->left, 2 * index + 1, totalNodes) &&
           isCompleteBinaryTree(node->right, 2 * index + 2, totalNodes);
}

void freeTree(TreeNode* node) {
    if (node == NULL)
        return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int countNodes(TreeNode* node) {
    if (node == NULL)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

void inputTree(TreeNode** node) {
    int data;
    printf("请输入节点的值（-1表示空节点）: ");
    scanf("%d", &data);
    if (data == -1)
        return;
    *node = createNode(data);
    printf("输入 %d 的左子节点:\n", data);
    inputTree(&((*node)->left));
    printf("输入 %d 的右子节点:\n", data);
    inputTree(&((*node)->right));
}

int main() {
    TreeNode* root = NULL;

    printf("输入二叉树的节点值和关系（按先序遍历顺序）:\n");
    inputTree(&root);

    printf("满二叉树？%s\n", isFullBinaryTree(root) ? "是" : "不是");
    printf("完全二叉树？%s\n", isCompleteBinaryTree(root, 0, countNodes(root)) ? "是" : "不是");

    // 释放内存
    freeTree(root);

    return 0;
}
