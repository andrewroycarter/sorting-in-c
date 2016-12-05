//
//  main.c
//  Sort
//
//  Created by Andrew Carter on 11/29/16.
//  Copyright © 2016 Andrew Carter. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <memory.h>
#include <time.h>

#include "utility.h"
#include "bubble.h"
#include "insertion.h"

void profile_bubble_sort(const void *list, int64_t n, size_t size);
void profile_insertion_sort(const void *list, int64_t n, size_t size);

int main(int argc, const char * argv[]) {
    int64_t n = 5;
    
    int64_t *list = calloc(n, sizeof(int64_t));
    create_list(list, n);
    
    profile_sort(bubble_sort, compare_int64_t, pretty_print_int64_t, list, n, sizeof(*list));
    profile_sort(insertion_sort, compare_int64_t, pretty_print_int64_t, list, n, sizeof(*list));
    
    free(list);
    
    return 0;
}

void profile_bubble_sort(const void *list, int64_t n, size_t size) {
    
}

void profile_insertion_sort(const void *list, int64_t n, size_t size) {
    
}

