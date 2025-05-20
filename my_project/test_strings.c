#include <stdio.h>
#include <assert.h>
#include "../include/asm_functions.h"

void test_is_empty() {
    assert(is_empty_asm("") == true);
    assert(is_empty_asm("Hello") == false);
    printf("is_empty tests passed!\n");
}

void test_strlen() {
    assert(strlen_asm("") == 0);
    assert(strlen_asm("a") == 1);
    assert(strlen_asm("hello") == 5);
    printf("strlen tests passed!\n");
}

int main() {
    test_is_empty();
    test_strlen();
    return 0;
}
