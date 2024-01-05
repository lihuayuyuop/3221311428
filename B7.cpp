#include <stdio.h>

// �鲢����ĸ������������ںϲ�������������
int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;        // �����������ʼ����
    int j = mid + 1;     // �����������ʼ����
    int k = left;        // �ϲ����������ʼ����
    int count = 0;       // ͳ�ƽ�������

    // �Ƚ������������Ԫ�أ�����С��Ԫ�ط�����ʱ������
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // �����������е�Ԫ�ش������������е�Ԫ��ʱ�����н�����������ͳ�ƽ�������
            temp[k++] = arr[j++];
            count += mid - i + 1;
        }
    }

    // ��ʣ���Ԫ�ظ��Ƶ���ʱ������
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // ����ʱ�����е�Ԫ�ظ��ƻ�ԭ����
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return count;
}

// �鲢������
int mergeSort(int arr[], int temp[], int left, int right) {
    int count = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        // �ֱ��������������й鲢���򣬲��ۼƽ�������
        count += mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid + 1, right);

        // �ϲ����������飬���ۼƽ�������
        count += merge(arr, temp, left, mid, right);
    }

    return count;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int temp[N];
    int minSteps = mergeSort(arr, temp, 0, N - 1);

    printf("%d\n", minSteps);

    return 0;
}

