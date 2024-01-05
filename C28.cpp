
#include <stdio.h>
#include <stdlib.h>

// ��������������������ݽṹ
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// �����½��ĺ���
TreeNode* createNewNode(int data) {
    TreeNode* newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// �����½��ĺ���
TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        return createNewNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// ���ҽ�㲢���·���ĺ���
TreeNode* search(TreeNode* root, int data) {
    TreeNode* node = root;
    while (node != NULL) {
        printf("%d->", node->data);
        if (data < node->data) {
            node = node->left;
        } else if (data > node->data) {
            node = node->right;
        } else {
            printf("Found %d\n", data);
            return node;
        }
    }
    printf("Not found %d\n", data);
    return NULL;
}

// ���ٶ����������ĺ���
void destroyTree(TreeNode* root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}

int main() {
    // ��ȡ����Ĺؼ��� K ��һ����������������������
    int k, n;
    scanf("%d", &k);
    scanf("%d", &n);
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        root = insert(root, num);
    }

    // ���ҹؼ��ֲ����·��
    printf("Path to %d: ", k);
    search(root, k);

    // ���ٶ���������
    destroyTree(root);

    return 0;
}
