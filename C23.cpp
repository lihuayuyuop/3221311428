#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    printf("������һ��Ӣ�ľ���: ");
    fgets(sentence, 1000, stdin);
    
    // ȥ����ĩ���з�
    if (sentence[strlen(sentence) - 1] == '\n') {
        sentence[strlen(sentence) - 1] = '\0';
    }
    
    // ȥ�����׿ո�
    int i = 0;
    while (isspace(sentence[i])) {
        i++;
    }
    memmove(sentence, sentence + i, strlen(sentence) - i + 1);
    
    // ȥ������Ŀո�
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
    
    printf("��ʽ����ľ���: %s\n", formattedSentence);
    
    return 0;
}
