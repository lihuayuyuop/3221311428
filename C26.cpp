#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

typedef struct node {
    int data;
    struct node *lchild, *rchild;
} Node;

int arr[MAXN];
int idx = 0;

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->lchild);
    arr[idx++] = root->data;
    inorder(root->rchild);
}

void insert(Node** root, int x) {
    if (*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));
        (*root)->data = x;
        (*root)->lchild = (*root)->rchild = NULL;
        return;
    }
    if (x < (*root)->data) {
        insert(&((*root)->lchild), x);
    } else {
        insert(&((*root)->rchild), x);
    }
}

Node* create(int data[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; ++i) {
        insert(&root, data[i]);
    }
    return root;
}

Node* search(Node* root, int x) {
    if (root == NULL) return NULL;
    if (root->data == x) return root;
    if (x < root->data) return search(root->lchild, x);
    else return search(root->rchild, x);
}

Node* LCA(Node* root, Node* p, Node* q) {
    if (root == NULL) return NULL;
    if (p->data < root->data && q->data < root->data) {
        return LCA(root->lchild, p, q);
    } else if (p->data > root->data && q->data > root->data) {
        return LCA(root->rchild, p, q);
    } else {
        return root;
    }
}

int main() {
    int n, i, j;
    scanf("%d %d %d", &n, &i, &j);
    int data[MAXN];
    for (int k = 0; k < n; ++k) {
        scanf("%d", &data[k]);
    }
    Node* root = create(data, n);
    Node* p = search(root, i);
    Node* q = search(root, j);
    Node* lca = LCA(root, p, q);
    printf("%d %d\n", lca->data, lca->data);
    return 0;
}
