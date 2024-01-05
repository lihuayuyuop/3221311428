#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

StackNode* createStackNode(int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(StackNode* top) {
    return top == NULL;
}

void push(StackNode** top, int data) {
    StackNode* newNode = createStackNode(data);
    newNode->next = *top;
    *top = newNode;
}

int pop(StackNode** top) {
    if (isEmpty(*top)) {
        printf("栈为空\n");
        return -1;
    }
    int data = (*top)->data;
    StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

void convertDecimalToBinary(int number) {
    StackNode* stack = NULL;
    
    while (number > 0) {
        int remainder = number % 2;
        push(&stack, remainder);
        number /= 2;
    }
    
    printf("二进制表示: ");
    while (!isEmpty(stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

void convertDecimalToOctal(int number) {
    StackNode* stack = NULL;
    
    while (number > 0) {
        int remainder = number % 8;
        push(&stack, remainder);
        number /= 8;
    }
    
    printf("八进制表示: ");
    while (!isEmpty(stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

void convertDecimalToHexadecimal(int number) {
    StackNode* stack = NULL;
    
    while (number > 0) {
        int remainder = number % 16;
        if (remainder < 10) {
            push(&stack, remainder);
        } else {
            push(&stack, remainder + 55); // 将余数转换为对应的十六进制字符
        }
        number /= 16;
    }
    
    printf("十六进制表示: ");
    while (!isEmpty(stack)) {
        int data = pop(&stack);
        if (data < 10) {
            printf("%d", data);
        } else {
            printf("%c", data);
        }
    }
    printf("\n");
}

int main() {
    int number;
    printf("请输入一个十进制数: ");
    scanf("%d", &number);
    
    convertDecimalToBinary(number);
    convertDecimalToOctal(number);
    convertDecimalToHexadecimal(number);
    
    return 0;
}
