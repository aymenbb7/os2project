#include <stdio.h>
#include <assert.h>
#include "../include/asm_functions.h"

void test_array_max() {
    int arr1[] = {1, 2, 3, 4, 5};
    assert(array_max_asm(arr1, 5) == 5);
    
    int arr2[] = {-5, -3, -1};
    assert(array_max_asm(arr2, 3) == -1);
    printf("array_max tests passed!\n");
}

void test_array_reverse() {
    int arr[] = {1, 2, 3, 4, 5};
    array_reverse_asm(arr, 5);
    assert(arr[0] == 5);
    assert(arr[4] == 1);
    printf("array_reverse tests passed!\n");
}

int main() {
    test_array_max();
    test_array_reverse();
    return 0;
}
