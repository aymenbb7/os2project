#include <stdio.h>
#include <assert.h>
#include "../include/asm_functions.h"

void test_factorial() {
    assert(factorial_asm(0) == 1);
    assert(factorial_asm(1) == 1);
    assert(factorial_asm(5) == 120);
    assert(factorial_asm(10) == 3628800);
    printf("Factorial tests passed!\n");
}

void test_lcm() {
    assert(lcm_asm(12, 18) == 36);
    assert(lcm_asm(7, 5) == 35);
    printf("LCM tests passed!\n");
}

int main() {
    test_factorial();
    test_lcm();
    return 0;
}
