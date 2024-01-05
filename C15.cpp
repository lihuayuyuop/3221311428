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
        (*head)->next = *head;
        return;
    }
    
    Node* tail = *head;
    while (tail->next != *head) {
        tail = tail->next;
    }
    
    tail->next = newNode;
    newNode->next = *head;
}

void deleteNode(Node** head, Node* target) {
    if (*head == NULL || target == NULL) {
        return;
    }
    
    if (*head == target) {
        Node* tail = *head;
        while (tail->next != *head) {
            tail = tail->next;
        }
        tail->next = (*head)->next;
        *head = (*head)->next;
        free(target);
        return;
    }
    
    Node* prev = *head;
    Node* current = (*head)->next;
    while (current != *head) {
        if (current == target) {
            prev->next = current->next;
            free(target);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void josephusCircle(int totalPeople, int interval) {
    Node* head = NULL;
    for (int i = 1; i <= totalPeople; i++) {
        appendNode(&head, i);
    }
    
    Node* current = head;
    while (current->next != current) {
        for (int i = 1; i < interval; i++) {
            current = current->next;
        }
        
        printf("����̭���ˣ�%d\n", current->value);
        Node* next = current->next;
        deleteNode(&head, current);
        current = next;
    }
    
    printf("���ʣ�µ��ˣ�%d\n", current->value);
    free(current);
}

int main() {
    int totalPeople, interval;
    
    printf("�������������ͱ���������ÿո�ָ���");
    scanf("%d %d", &totalPeople, &interval);
    
    josephusCircle(totalPeople, interval);
    
    return 0;
}
