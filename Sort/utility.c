//
//  utility.c
//  Sort
//
//  Created by Andrew Carter on 12/5/16.
//  Copyright © 2016 Andrew Carter. All rights reserved.
//

#include <stdio.h>
#include <inttypes.h>
#include <memory.h>
#include <stdlib.h>
#include <time.h>

#include "utility.h"

void pretty_print_intmax_t(const void *list, intmax_t n, size_t size) {
    for (intmax_t i = 0; i < n; i++) {
        if (i != 0) {
            printf(", ");
        }
        intmax_t value = *((intmax_t *)list + i);
        printf("%" PRIdMAX, value);
    }
    printf(".\n");
}

comparison_result compare_intmax_t(const void *lhs, const void *rhs) {
    intmax_t left = *((intmax_t *)(lhs));
    intmax_t right = *((intmax_t *)(rhs));
    
    comparison_result result = same;
    
    if (left > right) {
        result = ascending;
    } else if (left < right) {
        result = descending;
    }
    
    return result;
}

void create_list(intmax_t *dest, intmax_t n) {
    for (intmax_t i = 0; i < n; i++) {
        intmax_t random = arc4random() % 10;
        memmove(dest + i, &random, sizeof(intmax_t));
    }
}

void profile_sorter(sorter sort, comparator compare, list_printer printer, bool print_list, const void *list, intmax_t n, size_t size) {
    void *listCopy = calloc(n, size);
    memcpy(listCopy, list, size * n);
    
    puts("Sorting...");
    
    if (print_list) {
        printer(listCopy, n, size);
    }
    
    clock_t begin = clock();
    sort(listCopy, n, size, compare);
    clock_t end = clock();
    double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("Sorted in %f seconds.\n", timeSpent);
    
    if (print_list) {
        printer(listCopy, n, size);
    }
    
    puts("");
    
    free(listCopy);
}
