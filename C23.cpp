#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    printf("请输入一个英文句子: ");
    fgets(sentence, 1000, stdin);
    
    // 去掉行末换行符
    if (sentence[strlen(sentence) - 1] == '\n') {
        sentence[strlen(sentence) - 1] = '\0';
    }
    
    // 去掉行首空格
    int i = 0;
    while (isspace(sentence[i])) {
        i++;
    }
    memmove(sentence, sentence + i, strlen(sentence) - i + 1);
    
    // 去掉多余的空格
    char formattedSentence[1000];
    int j = 0;
    int spaceCount = 0;
    for (i = 0; i < strlen(sentence); i++) {
        if (isspace(sentence[i])) {
            spaceCount++;
        } else {
            if (spaceCount > 0) {
                formattedSentence[j++] = ' ';
                spaceCount = 0;
            }
            formattedSentence[j++] = sentence[i];
        }
    }
    formattedSentence[j] = '\0';
    
    printf("格式化后的句子: %s\n", formattedSentence);
    
    return 0;
}
