#include <stdio.h>
#include <stdlib.h>
void max_heapify(int arr[], int n, int i);
void swap(int *a, int *b);
void min_heapify(int arr[], int n, int i);
void merge(int arr[], int left, int mid, int right);
// ϣ������
void shell_sort(int arr[], int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// ��������
void quick_sort(int arr[], int left, int right) {
    if (left >= right) return;
    int i = left, j = right, pivot = arr[left];
    while (i < j) {
        while (i < j && arr[j] >= pivot) j--;
        if (i < j) arr[i++] = arr[j];
        while (i < j && arr[i] < pivot) i++;
        if (i < j) arr[j--] = arr[i];
    }
    arr[i] = pivot;
    quick_sort(arr, left, i - 1);
    quick_sort(arr, i + 1, right);
}

// ������
void heap_sort(int arr[], int n, int is_max_heap) {
    int i;
    if (is_max_heap) {
        for (i = n / 2 - 1; i >= 0; i--) {
            max_heapify(arr, n, i);
        }
        for (i = n - 1; i > 0; i--) {
            swap(&arr[0], &arr[i]);
            max_heapify(arr, i, 0);
        }
    } else {
        for (i = n / 2 - 1; i >= 0; i--) {
            min_heapify(arr, n, i);
        }
        for (i = n - 1; i > 0; i--) {
            swap(&arr[0], &arr[i]);
            min_heapify(arr, i, 0);
        }
    }
}

void max_heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, n, largest);
    }
}

void min_heapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        min_heapify(arr, n, smallest);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// �鲢����
void merge_sort(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void merge(int arr[], int left, int mid, int right) {
    int *temp = (int *)malloc((right - left + 1) * sizeof(int));
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
    free(temp);
}

// ��������
void counting_sort(int arr[], int n) {
    int max = arr[0], i, j, k = 0;
    for (i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    int *count = (int *)calloc(max + 1, sizeof(int));
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (i = 0; i <= max; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[k++] = i;
        }
    }
    free(count);
}

int main() {
    int n;
    printf("���������鳤�ȣ�");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("����������Ԫ�أ�");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("ԭʼ���У�");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // ϣ������
    shell_sort(arr, n);
    printf("ϣ����������");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // ��������
    quick_sort(arr, 0, n - 1);
    printf("������������");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // �����򣨴���ѣ�
    heap_sort(arr, n, 1);
    printf("�����򣨴���ѣ������");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // ������С���ѣ�
    heap_sort(arr, n, 0);
    printf("������С���ѣ������");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // �鲢����
    merge_sort(arr, 0, n - 1);
    printf("�鲢��������");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // ��������
    counting_sort(arr, n);
    printf("������������");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
