//
//  bubble.c
//  Sort
//
//  Created by Andrew Carter on 12/5/16.
//  Copyright © 2016 Andrew Carter. All rights reserved.
//

#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

#include "bubble.h"

void bubble_sort(void *list, int64_t n, size_t size, CompareFunction compare) {
    bool sorted = false;
    
    while (!sorted) {
        sorted = true;
        
        for (int64_t i = 0; i < n - 1; i++) {
            void *lhs = list + (size * i);
            void *rhs = list + (size * (i + 1));
            
            comparison_result result = compare(lhs, rhs);
            if (result == ascending) {
                void *swap = malloc(size);
                memcpy(swap, lhs, size);
                memcpy(lhs, rhs, size);
                memcpy(rhs, swap, size);
                free(swap);
                
                sorted = false;
            }
        }
    }
}
