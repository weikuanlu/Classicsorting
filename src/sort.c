#include <stdio.h>

void display(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

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