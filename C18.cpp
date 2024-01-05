#include <stdio.h>
#include <stdlib.h>

// ����˫��ѭ������Ľڵ�ṹ
typedef struct node {
    int val;
    struct node *prev;
    struct node *next;
} Node;

// �����ͷ����˫��ѭ������ṹ
typedef struct list {
    Node *head;
    int size;
} List;

// ��ʼ��˫��ѭ������
List* initList() {
    List *l = (List*)malloc(sizeof(List));
    Node *head = (Node*)malloc(sizeof(Node));
    head->prev = head;
    head->next = head;
    l->head = head;
    l->size = 0;
    return l;
}

// ��˫��ѭ�������ĩβ���һ��Ԫ��
void addNode(List *l, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->prev = l->head->prev;
    l->head->prev->next = newNode;
    newNode->next = l->head;
    l->head->prev = newNode;
    l->size++;
}

// ��ʾ˫��ѭ������
void displayList(List *l) {
    Node *p = l->head->next;
    while (p != l->head) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

// ���������ϵĽ���
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

// ���������ϵĲ���
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
    // ��������A
    printf("�����뼯��A��Ԫ�أ���-1������");
    List *A = initList();
    int val;
    scanf("%d", &val);
    while (val != -1) {
        addNode(A, val);
        scanf("%d", &val);
    }
    printf("����A: ");
    displayList(A);

    // ��������B
    printf("�����뼯��B��Ԫ�أ���-1������");
    List *B = initList();
    scanf("%d", &val);
    while (val != -1) {
        addNode(B, val);
        scanf("%d", &val);
    }
    printf("����B: ");
    displayList(B);

    // �󽻼�
    List *C = getIntersection(A, B);
    printf("A �� B: ");
    displayList(C);

    // �󲢼�
    List *D = getUnion(A, B);
    printf("A �� B: ");
    displayList(D);

    return 0;
}
