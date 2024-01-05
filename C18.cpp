#include <stdio.h>
#include <stdlib.h>

// 定义双向循环链表的节点结构
typedef struct node {
    int val;
    struct node *prev;
    struct node *next;
} Node;

// 定义带头结点的双向循环链表结构
typedef struct list {
    Node *head;
    int size;
} List;

// 初始化双向循环链表
List* initList() {
    List *l = (List*)malloc(sizeof(List));
    Node *head = (Node*)malloc(sizeof(Node));
    head->prev = head;
    head->next = head;
    l->head = head;
    l->size = 0;
    return l;
}

// 在双向循环链表的末尾添加一个元素
void addNode(List *l, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->prev = l->head->prev;
    l->head->prev->next = newNode;
    newNode->next = l->head;
    l->head->prev = newNode;
    l->size++;
}

// 显示双向循环链表
void displayList(List *l) {
    Node *p = l->head->next;
    while (p != l->head) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

// 求两个集合的交集
List* getIntersection(List *l1, List *l2) {
    List *res = initList();
    Node *p1 = l1->head->next;
    while (p1 != l1->head) {
        Node *p2 = l2->head->next;
        while (p2 != l2->head) {
            if (p1->val == p2->val) {
                addNode(res, p1->val);
                break;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return res;
}

// 求两个集合的并集
List* getUnion(List *l1, List *l2) {
    List *res = initList();
    Node *p1 = l1->head->next;
    while (p1 != l1->head) {
        addNode(res, p1->val);
        p1 = p1->next;
    }
    Node *p2 = l2->head->next;
    while (p2 != l2->head) {
        Node *p = res->head->next;
        while (p != res->head) {
            if (p2->val == p->val) {
                break;
            }
            p = p->next;
        }
        if (p == res->head) {
            addNode(res, p2->val);
        }
        p2 = p2->next;
    }
    return res;
}

int main() {
    // 创建集合A
    printf("请输入集合A的元素，以-1结束：");
    List *A = initList();
    int val;
    scanf("%d", &val);
    while (val != -1) {
        addNode(A, val);
        scanf("%d", &val);
    }
    printf("集合A: ");
    displayList(A);

    // 创建集合B
    printf("请输入集合B的元素，以-1结束：");
    List *B = initList();
    scanf("%d", &val);
    while (val != -1) {
        addNode(B, val);
        scanf("%d", &val);
    }
    printf("集合B: ");
    displayList(B);

    // 求交集
    List *C = getIntersection(A, B);
    printf("A ∩ B: ");
    displayList(C);

    // 求并集
    List *D = getUnion(A, B);
    printf("A ∪ B: ");
    displayList(D);

    return 0;
}
