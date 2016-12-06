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

void insertion_sort(void *list, intmax_t n, size_t size, CompareFunction compare) {
    for (intmax_t i = 0; i < n; i++) {
        void *current = malloc(size);
        memcpy(current, list + (size * i), size);
        
        for (intmax_t j = i; j > 0; j--) {
            if (j - 2 < 0) {
                void *right = list + (size * (j - 1));
                comparison_result result = compare(current, right);
                bool shouldMove = result == same || result == descending;
                
                if (shouldMove) {
                    memmove(list + (size * j), list + (size * (j - 1)), (i - (j - 1)) * size);
                    memcpy(list + (size * (j - 1)), current, size);
                    break;
                }
            } else {
                void *right = list + (size * (j - 1));
                void *left = list + (size * (j - 2));
                
                comparison_result leftResult = compare(current, left);
                comparison_result rightResult = compare(current, right);
                
                bool shouldMoveLeft = leftResult == ascending || leftResult == same;
                bool shouldMoveRight = rightResult == descending || rightResult == same;
                bool shouldMove = shouldMoveLeft && shouldMoveRight;
                
                if (shouldMove) {
                    memmove(list + (size * j), list + (size * (j - 1)), (i - (j - 1)) * size);
                    memcpy(list + (size * (j - 1)), current, size);
                    break;
                }
            }
        }
        
        free(current);
    }
}
