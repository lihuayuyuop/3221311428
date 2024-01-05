#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ��
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// �����������ڵ�
TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ���������������ڵ�
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

// ��������������н�����������ֵ֮��Ľڵ��ܺ�
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
    // ��������������
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->right = createNode(18);

    // ���巶Χֵ
    int low = 7;
    int high = 15;

    // ����ڵ��ܺ�
    int sum = rangeSumBST(root, low, high);

    printf("�ڵ��ܺ�Ϊ: %d\n", sum);

    return 0;
}
