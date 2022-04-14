#include <stdio.h>

void display(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 冒泡排序
void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < (n - i - 1); j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// 选择排序
void select_sort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int min_num = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min_num] > arr[j]) {
                min_num = j;
            }
        }
        if (min_num != i) {
            int temp = arr[min_num];
            arr[min_num] = arr[i];
            arr[i] = temp;
        }
    }
}


// 插入排序
void insert_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key; 
    }
}

// 快速排序
int partition(int *arr, int left, int right) {
    int i = left - 1;
    int pivot = arr[right];
    for (int j = left; j <= right; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp1 = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp1;
    return i+1;
}
void quick_sort(int *arr, int left, int right) {
    if (left < right) {
        int mid = partition(arr, left, right);
        quick_sort(arr, left, mid-1);
        quick_sort(arr, mid+1, right);
    }
}

// 堆排序
void headify(int *arr, int n, int i) {
    int c1 = 2*i + 1;
    int c2 = 2*i + 2;
    int max_index = i;
    while (c1 < n && arr[max_index] < arr[c1]) {
        max_index = c1;
    }
    while (c2 < n && arr[max_index] < arr[c2]) {
        max_index = c2;
    }

    if (i != max_index) {
        int temp = arr[max_index];
        arr[max_index] = arr[i];
        arr[i] = temp;
        headify(arr, n, max_index);
    }
}

void build_heap(int *arr, int n) {
    int last_node = n - 1;
    int p = (last_node - 1) / 2;
    for (int i = p; i > -1; i--) {
        headify(arr, n, i);
    }
}
void heap_sort(int *arr, int len) {
    build_heap(arr, len);
    for (int i = len - 1; i > -1; i--) {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        headify(arr, i, 0);
    }
}

// 归并排序
void merge(int *arr, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int *temp = new int[right-left+1];
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int i = left, k = 0; i <= right; i++,k++) {
        arr[i] = temp[k];
    }
    
    delete[] temp;
}
void merge_sort(int *arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}