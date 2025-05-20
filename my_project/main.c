#include <stdio.h>
#include "../include/asm_functions.h"

int main() {
    // Number operations demo
    printf("LCM of 12 and 18: %u\n", lcm_asm(12, 18));
    printf("Factorial of 5: %lu\n", factorial_asm(5));
    
    char bin_buf[33];
    int_to_binary_asm(25, bin_buf);
    printf("25 in binary: %s\n", bin_buf);
    
    // String operations demo
    printf("Is empty string empty? %s\n", is_empty_asm("") ? "Yes" : "No");
    printf("Length of 'Hello': %zu\n", strlen_asm("Hello"));
    
    // Array operations demo
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr)/sizeof(arr[0]);
    
    printf("Max in array: %d\n", array_max_asm(arr, len));
    array_reverse_asm(arr, len);
    printf("Reversed array: ");
    for (size_t i = 0; i < len; i++) printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
