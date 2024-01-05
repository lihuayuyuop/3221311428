#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// ����һ���½ڵ�
Node* newNode(int data)
 {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Ѱ�������ڵ�������������
Node* findLowestCommonAncestor(Node* root, int i, int j) {
    if (root == NULL || root->data == i || root->data == j) {
        return root;
    }

    Node* left = findLowestCommonAncestor(root->left, i, j);
    Node* right = findLowestCommonAncestor(root->right, i, j);

    if (left != NULL && right != NULL) {
        return root;
    }

    return (left != NULL) ? left : right;
}

int main() {
    // ����������
    Node* root = newNode(1);//��������� 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int i, j;
    printf("�����������ڵ��ֵ��");
    scanf("%d %d", &i, &j);

    Node* ancestor = findLowestCommonAncestor(root, i, j);
    printf("����������ȵ�ֵΪ��%d\n", ancestor->data);

    return 0;
}

