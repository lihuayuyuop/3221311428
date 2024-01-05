#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* preProcess(char* s) {
    int n = strlen(s);
    char* new_s = (char*)malloc((2 * n + 3) * sizeof(char));
    new_s[0] = '^';
    new_s[1] = '#';
    for (int i = 0; i < n; i++) {
        new_s[2 * i + 2] = s[i];
        new_s[2 * i + 3] = '#';
    }
    new_s[2 * n + 2] = '$';
    return new_s;
}

char* longestPalindrome(char* s) {
    char* T = preProcess(s);
    int n = strlen(T);
    int* P = (int*)malloc(n * sizeof(int));
    memset(P, 0, n * sizeof(int));
    int C = 0, R = 0;
    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        int i_mirror = 2 * C - i;
        if (R > i) {
            P[i] = P[i_mirror] < R - i ? P[i_mirror] : R - i;
        } else {
            P[i] = 0;
        }
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
            P[i]++;
        }
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    int start = (centerIndex - maxLen) / 2;
    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    free(T);
    free(P);
    return result;
}

int main() {
    char s[100];
    printf("请输入一段序列：");
    scanf("%s", s);
    char* palindrome = longestPalindrome(s);
    printf("最长回文子序列为：%s\n", palindrome);
    free(palindrome);
    return 0;
}

