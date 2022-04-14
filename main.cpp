#include <stdio.h>
#include "head/sort.h"

#include <iostream>
using namespace std;

int main() {
    int arr1[10] = {15,22,8,29,33,55,68,42,2,10};
    int arr2[10] = {15,22,8,29,33,55,68,42,2,10};
    int arr3[10] = {15,22,8,29,33,55,68,42,2,10};
    int arr4[10] = {15,22,8,29,33,55,68,42,2,10};
    int arr5[10] = {15,22,8,29,33,55,68,42,2,10};
    
    // 1:
    printf("bubble_sort: \n");
    bubble_sort(arr1, 10);
    display(arr1, 10);

    // 2：
    printf("select_sort: \n");
    select_sort(arr2, 10);
    display(arr2, 10);

    // 3: 
    printf("insert_sort: \n");
    insert_sort(arr3, 10);
    display(arr3, 10);

    // 4:
    printf("quick_sort: \n");
    quick_sort(arr4, 0, 9);
    display(arr4, 10);

    // 5:
    printf("heap_sort: \n");
    heap_sort(arr5, 10);
    display(arr4, 10);
    
    // 6:
    printf("merge_sort: \n");
    merge_sort(arr5, 0, 9);
    display(arr4, 10);
}