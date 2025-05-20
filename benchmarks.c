#include <stdio.h>
#include <time.h>
#include "../include/asm_functions.h"

// C implementations for comparison
unsigned long factorial_c(unsigned int n) {
    unsigned long result = 1;
    for (unsigned int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

void run_benchmarks() {
    const int iterations = 10000000;
    clock_t start, end;
    double asm_time, c_time;
    
    // Benchmark factorial
    start = clock();
    for (int i = 0; i < iterations; i++) {
        factorial_asm(10);
    }
    end = clock();
    asm_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    start = clock();
    for (int i = 0; i < iterations; i++) {
        factorial_c(10);
    }
    end = clock();
    c_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("Factorial benchmark (10!):\n");
    printf("  ASM: %.6f sec\n", asm_time);
    printf("  C  : %.6f sec\n", c_time);
    printf("  Speedup: %.2fx\n", c_time / asm_time);
}
