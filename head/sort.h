#ifndef SORT_H_
#define SORT_H_

void display(int *arr, int n);
// 冒泡排序
void bubble_sort(int *arr, int n); 
// 选择排序
void select_sort(int *arr, int n);
// 插入排序
void insert_sort(int *arr, int n);
// 快速排序
void quick_sort(int *arr, int left, int right);
// 堆排序
void heap_sort(int *arr, int n);
// 归并排序
void merge_sort(int *arr, int left, int right);

#endif