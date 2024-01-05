#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node** head, int value) {
    Node* newNode = createNode(value);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* tail = *head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    
    tail->next = newNode;
}

void splitList(Node* head, Node** oddHead, Node** evenHead) {
    Node* current = head;
    int position = 1;
    while (current != NULL) {
        if (position % 2 == 1) {
            appendNode(oddHead, current->value);
        } else {
            appendNode(evenHead, current->value);
        }
        current = current->next;
        position++;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int value;
    printf("������ 10 �����ϵ���������������\n");
    for (int i = 1; i <= 10; i++) {
        scanf("%d", &value);
        appendNode(&head, value);
    }
    
    Node* oddHead = NULL;
    Node* evenHead = NULL;
    splitList(head, &oddHead, &evenHead);
    
    printf("ԭ����");
    printList(head);
    printf("����λ������");
    printList(oddHead);
    printf("ż��λ������");
    printList(evenHead);
    
    return 0;
}
