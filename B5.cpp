#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct Node {
    int w;
    int left;
    int right;
} Node;

void preOrderTraversal(Node *nodes, int index) {
    if (index == -1) {
        return;
    }
    printf("%d ", nodes[index].w);
    preOrderTraversal(nodes, nodes[index].left);
    preOrderTraversal(nodes, nodes[index].right);
}

void inOrderTraversal(Node *nodes, int index) {
    if (index == -1) {
        return;
    }
    inOrderTraversal(nodes, nodes[index].left);
    printf("%d ", nodes[index].w);
    inOrderTraversal(nodes, nodes[index].right);
}

void postOrderTraversal(Node *nodes, int index) {
    if (index == -1) {
        return;
    }
    postOrderTraversal(nodes, nodes[index].left);
    postOrderTraversal(nodes, nodes[index].right);
    printf("%d ", nodes[index].w);
}

int main() {
    int n;
    scanf("%d", &n);

    Node nodes[MAX_NODES];
    int i;
    for (i = 1; i <= n; i++) {
        int value, leftIndex, rightIndex;
        scanf("%d %d %d", &value, &leftIndex, &rightIndex);
        nodes[i].w = value;//Êý¾Ý 
        nodes[i].left = leftIndex;
        nodes[i].right = rightIndex;
    }

    printf("Preorder traversal: ");
    preOrderTraversal(nodes, 1);
    printf("\n");

    printf("Inorder traversal: ");
    inOrderTraversal(nodes, 1);
    printf("\n");

    printf("Postorder traversal: ");
    postOrderTraversal(nodes, 1);
    printf("\n");

    return 0;
}

