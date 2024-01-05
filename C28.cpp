
#include <stdio.h>
#include <stdlib.h>

// 定义二叉排序树结点的数据结构
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 创建新结点的函数
TreeNode* createNewNode(int data) {
    TreeNode* newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 插入新结点的函数
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

// 查找结点并输出路径的函数
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

// 销毁二叉排序树的函数
void destroyTree(TreeNode* root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}

int main() {
    // 读取输入的关键字 K 和一组数字来构建二叉排序树
    int k, n;
    scanf("%d", &k);
    scanf("%d", &n);
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        root = insert(root, num);
    }

    // 查找关键字并输出路径
    printf("Path to %d: ", k);
    search(root, k);

    // 销毁二叉排序树
    destroyTree(root);

    return 0;
}
