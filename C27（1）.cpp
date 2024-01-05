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
        printf("�ڴ����ʧ��\n");
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
    printf("������ڵ��ֵ��-1��ʾ�սڵ㣩: ");
    scanf("%d", &data);
    if (data == -1)
        return;
    *node = createNode(data);
    printf("���� %d �����ӽڵ�:\n", data);
    inputTree(&((*node)->left));
    printf("���� %d �����ӽڵ�:\n", data);
    inputTree(&((*node)->right));
}

int main() {
    TreeNode* root = NULL;

    printf("����������Ľڵ�ֵ�͹�ϵ�����������˳��:\n");
    inputTree(&root);

    printf("����������%s\n", isFullBinaryTree(root) ? "��" : "����");
    printf("��ȫ��������%s\n", isCompleteBinaryTree(root, 0, countNodes(root)) ? "��" : "����");

    // �ͷ��ڴ�
    freeTree(root);

    return 0;
}
