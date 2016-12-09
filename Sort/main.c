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
#include "merge.h"


int main(int argc, const char * argv[]) {
    intmax_t n = 100;
    
    intmax_t *list = calloc(n, sizeof(intmax_t));
    create_list(list, n);
    
    profile_sorter(bubble_sort, compare_intmax_t, pretty_print_intmax_t, false, list, n, sizeof(*list));
    profile_sorter(insertion_sort, compare_intmax_t, pretty_print_intmax_t, false, list, n, sizeof(*list));
    profile_sorter(merge_sort, compare_intmax_t, pretty_print_intmax_t, false, list, n, sizeof(*list));

    free(list);
    
    return 0;
}
