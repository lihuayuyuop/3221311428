#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestPalindrome_Manacher(char* s) {
    int len = strlen(s);
    if (len == 0) return "";
    
    char* newStr = (char*)malloc(sizeof(char) * (2 * len + 2));
    newStr[0] = '$';
    newStr[1] = '#';
    int j = 2;
    for (int i = 0; i < len; i++) {
        newStr[j++] = s[i];
        newStr[j++] = '#';
    }
    newStr[j] = '\0';
    
    int newLen = 2 * len + 1;
    int* p = (int*)malloc(sizeof(int) * newLen);
    memset(p, 0, sizeof(int) * newLen);
    int center = 0, right = 0;
    int maxLen = 0, start = 0;
    
    for (int i = 1; i < newLen; i++) {
        if (i < right) {
            p[i] = (p[2 * center - i] < right - i) ? p[2 * center - i] : (right - i);
        } else {
            p[i] = 1;
        }
        
        while (newStr[i + p[i]] == newStr[i - p[i]]) {
            p[i]++;
        }
        
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
        
        if (p[i] > maxLen) {
            maxLen = p[i];
            start = (i - maxLen) / 2;
        }
    }
    
    char* res = (char*)malloc(sizeof(char) * (maxLen + 1));
    strncpy(res, s + start, maxLen);
    res[maxLen] = '\0';
    
    free(newStr);
    free(p);
    
    return res;
}

int main() {
    char s[100]; // 假设最大输入长度不超过100
    
    printf("请输入一个字符串：");
    scanf("%s", s);
    
    char* result_Manacher = longestPalindrome_Manacher(s);
    printf("Manacher算法：最长回文子串：%s\n", result_Manacher);
    free(result_Manacher);
    
    return 0;
}
