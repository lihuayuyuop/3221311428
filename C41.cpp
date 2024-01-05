#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 创建二叉树节点
TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 向二叉搜索树插入节点
TreeNode* insertNode(TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else if (val > root->val) {
        root->right = insertNode(root->right, val);
    }
    
    return root;
}

// 计算二叉搜索树中介于两个给定值之间的节点总和
int rangeSumBST(TreeNode* root, int low, int high) {
    if (root == NULL) {
        return 0;
    }
    
    if (root->val < low) {
        return rangeSumBST(root->right, low, high);
    }
    
    if (root->val > high) {
        return rangeSumBST(root->left, low, high);
    }
    
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

int main() {
    // 创建二叉搜索树
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->right = createNode(18);

    // 定义范围值
    int low = 7;
    int high = 15;

    // 计算节点总和
    int sum = rangeSumBST(root, low, high);

    printf("节点总和为: %d\n", sum);

    return 0;
}
