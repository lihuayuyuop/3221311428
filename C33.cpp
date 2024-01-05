#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

typedef struct Node {
    char ch;
    double freq;
    struct Node *left, *right;
} Node;

Node *heap[MAXN];
int size = 0;

void push(Node *node) {
    int i = ++size;
    while (i > 1 && node->freq < heap[i / 2]->freq) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = node;
}

Node *pop() {
    Node *res = heap[1];
    Node *tmp = heap[size--];
    int parent = 1, child = 2;
    while (child <= size) {
        if (child < size && heap[child]->freq > heap[child + 1]->freq) {
            child++;
        }
        if (tmp->freq <= heap[child]->freq) {
            break;
        }
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = tmp;
    return res;
}

void huffman(Node *nodes[], int n) {
    for (int i = 0; i < n - 1; ++i) {
Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->left = pop();
        newNode->right = pop();
        newNode->freq = newNode->left->freq + newNode->right->freq;
        push(newNode);
    }
}

void printCode(Node *node, char *code) {
    if (node->left == NULL && node->right == NULL) {
        printf("%c: %s\n", node->ch, code);
    } else {
        char leftCode[MAXN], rightCode[MAXN];
        strcpy(leftCode, code);
        strcat(leftCode, "0");
        printCode(node->left, leftCode);
        strcpy(rightCode, code);
        strcat(rightCode, "1");
        printCode(node->right, rightCode);
    }
}

int main() {
    int n;
    printf("请输入字符个数：");
    scanf("%d", &n);

    Node *nodes[MAXN];
    char ch[MAXN];
    double freq[MAXN];

    for (int i = 0; i < n; ++i) {
        printf("请输入第%d个字符和其频率：", i + 1);
        scanf(" %c%lf", &ch[i], &freq[i]);

 nodes[i] = (Node *) malloc(sizeof(Node));
        nodes[i]->ch = ch[i];
        nodes[i]->freq = freq[i];
        nodes[i]->left = nodes[i]->right = NULL;

        push(nodes[i]);
    }

    huffman(nodes, n);

    char code[MAXN];
    printCode(heap[1], code);

    return 0;
}
