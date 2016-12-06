//
//  insertion.c
//  Sort
//
//  Created by Andrew Carter on 12/5/16.
//  Copyright © 2016 Andrew Carter. All rights reserved.
//

#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

#include "insertion.h"

void insertion_sort(void *list, intmax_t n, size_t size, comparator compare) {
    for (intmax_t i = 0; i < n; i++) {
        void *current = malloc(size);
        memcpy(current, list + (size * i), size);
        
        for (intmax_t j = i; j > 0; j--) {
            if (j - 2 < 0) {
                void *right = list + (size * (j - 1));
                comparison_result result = compare(current, right);
                bool should_move = result == same || result == descending;
                
                if (should_move) {
                    memmove(list + (size * j), list + (size * (j - 1)), (i - (j - 1)) * size);
                    memcpy(list + (size * (j - 1)), current, size);
                    break;
                }
            } else {
                void *right = list + (size * (j - 1));
                void *left = list + (size * (j - 2));
                
                comparison_result left_result = compare(current, left);
                comparison_result right_result = compare(current, right);
                
                bool should_move_left = left_result == ascending || left_result == same;
                bool should_move_right = right_result == descending || right_result == same;
                bool should_move = should_move_left && should_move_right;
                
                if (should_move) {
                    memmove(list + (size * j), list + (size * (j - 1)), (i - (j - 1)) * size);
                    memcpy(list + (size * (j - 1)), current, size);
                    break;
                }
            }
        }
        
        free(current);
    }
}
