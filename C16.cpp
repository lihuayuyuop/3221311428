#include <stdio.h>

int calculateDeletions(int arr[], int n) {
    if(n < 3) {
        return 0;
    }
    
    int deletions = 0;
    int prev_diff = arr[1] - arr[0];
    
    if(prev_diff == 0) {
        deletions++;
    }
    
    for(int i = 2; i < n; i++) {
        int diff = arr[i] - arr[i-1];
        
        if((prev_diff >= 0 && diff >= 0) || (prev_diff <= 0 && diff <= 0)) {
            deletions++;
        }
        
        prev_diff = diff;
    }
    
    return deletions;
}

int main() {
    int arr[100];
    int num;
    int index = 0;
    
    printf("�������������У���-1��������: ");
    while(1) {
        scanf("%d", &num);
        
        if(num == -1) {
            break;
        }
        
        arr[index] = num;
        index++;
    }
    
    int deletions = calculateDeletions(arr, index);
    
    if(deletions == 0) {
        printf("�ǰڶ�����\n");
    } else {
        printf("�ǰڶ����У���Ҫɾ�� %d ��Ԫ��\n", deletions);
    }
    
    return 0;
}
