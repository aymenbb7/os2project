#ifndef ASM_FUNCTIONS_H
#define ASM_FUNCTIONS_H

#include <stdbool.h>
#include <stddef.h>

// Number operations
unsigned int lcm_asm(unsigned int a, unsigned int b);
void int_to_binary_asm(unsigned int num, char* buffer);
unsigned long factorial_asm(unsigned int n);

// String operations
bool is_empty_asm(const char* str);
size_t strlen_asm(const char* str);

// Array operations
void array_reverse_asm(int* arr, size_t length);
int array_max_asm(const int* arr, size_t length);

#endif
