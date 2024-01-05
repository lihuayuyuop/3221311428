#include <stdio.h>

// 归并排序的辅助函数，用于合并两个有序数组
int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;        // 左子数组的起始索引
    int j = mid + 1;     // 右子数组的起始索引
    int k = left;        // 合并后数组的起始索引
    int count = 0;       // 统计交换次数

    // 比较左右子数组的元素，将较小的元素放入临时数组中
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // 当左子数组中的元素大于右子数组中的元素时，进行交换操作，并统计交换次数
            temp[k++] = arr[j++];
            count += mid - i + 1;
        }
    }

    // 将剩余的元素复制到临时数组中
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // 将临时数组中的元素复制回原数组
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return count;
}

// 归并排序函数
int mergeSort(int arr[], int temp[], int left, int right) {
    int count = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        // 分别对左右子数组进行归并排序，并累计交换次数
        count += mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid + 1, right);

        // 合并左右子数组，并累计交换次数
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

