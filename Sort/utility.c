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

#include "utility.h"

void pretty_print_int64_t(const void *list, int64_t n, size_t size) {
    for (int64_t i = 0; i < n; i++) {
        if (i != 0) {
            printf(", ");
        }
        int64_t value = *((int64_t *)list + i);
        printf("%" PRId64, value);
    }
    printf(".\n");
}

comparison_result compare_int64_t(const void *lhs, const void *rhs) {
    int64_t left = *((int64_t *)(lhs));
    int64_t right = *((int64_t *)(rhs));
    
    comparison_result result = same;
    
    if (left > right) {
        result = ascending;
    } else if (left < right) {
        result = descending;
    }
    
    return result;
}

void create_list(int64_t *dest, int64_t n) {
    for (int64_t i = 0; i < n; i++) {
        int64_t random = arc4random() % 10;
        memmove(dest + i, &random, sizeof(int64_t));
    }
}

void profile_sort(SortFunction sort_function, CompareFunction compare, ListPrintFunction print_function, const void *list, int64_t n, size_t size) {
    void *listCopy = calloc(n, size);
    memcpy(listCopy, list, size * n);
    
    puts("Sorting:");
    print_function(listCopy, n, size);
    sort_function(listCopy, n, size, compare);
    puts("Sorted:");
    print_function(listCopy, n, size);

    free(listCopy);
}
