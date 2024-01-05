#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10000

char a[MAXN], b[MAXN], c[MAXN];

void add(char *a, char *b, char *c) {
    int lena = strlen(a), lenb = strlen(b);
    int carry = 0, i = lena - 1, j = lenb - 1;
    int k = 0;

    while (i >= 0 || j >= 0 || carry > 0) {
        int x = i >= 0 ? a[i--] - '0' : 0;
        int y = j >= 0 ? b[j--] - '0' : 0;
        int z = x + y + carry;
        c[k++] = z % 10 + '0';
        carry = z / 10;
    }

    c[k] = '\0';
    int lenc = strlen(c);
    for (int i = 0; i < lenc / 2; ++i) {
        char temp = c[i];
        c[i] = c[lenc - i - 1];
        c[lenc - i - 1] = temp;
    }
}

void sub(char *a, char *b, char *c) {
    int lena = strlen(a), lenb = strlen(b);
    int borrow = 0, i = lena - 1, j = lenb - 1;
    int k = 0;

    while (i >= 0 || j >= 0) {
        int x = i >= 0 ? a[i--] - '0' : 0;
        int y = j >= 0 ? b[j--] - '0' : 0;
        int z = x - y - borrow;
        if (z < 0) {
            z += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        c[k++] = z + '0';
    }

    while (k > 1 && c[k - 1] == '0') {
        --k;
    }
    c[k] = '\0';
    int lenc = strlen(c);
    for (int i = 0; i < lenc / 2; ++i) {
        char temp = c[i];
        c[i] = c[lenc - i - 1];
        c[lenc - i - 1] = temp;
    }
}

void mul(char *a, char *b, char *c) {
    int lena = strlen(a), lenb = strlen(b);
    int *temp = (int *) malloc(sizeof(int) * (lena + lenb));
    memset(temp, 0, sizeof(int) * (lena + lenb));

    for (int i = lena - 1; i >= 0; --i) {
        for (int j = lenb - 1; j >= 0; --j) {
            int x = a[i] - '0', y = b[j] - '0';
            temp[i + j + 1] += x * y;
        }
    }

    for (int i = lena + lenb - 1; i > 0; --i) {
        temp[i - 1] += temp[i] / 10;
        temp[i] %= 10;
    }

    int k = 0;
    while (temp[k] == 0 && k < lena + lenb - 1) {
        ++k;
    }

    for (int i = k; i < lena + lenb; ++i) {
        c[i - k] = temp[i] + '0';
    }
    c[lena + lenb - k] = '\0';

    free(temp);
}

int main() {
    printf("请输入两个非常大的数字：\n");
    scanf("%s %s", a, b);

    add(a, b, c);
    printf("%s + %s = %s\n", a, b, c);

    sub(a, b, c);
    printf("%s - %s = %s\n", a, b, c);

    mul(a, b, c);
    printf("%s * %s = %s\n", a, b, c);

    return 0;
}
