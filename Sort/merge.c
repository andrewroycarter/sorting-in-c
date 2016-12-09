//
//  merge.c
//  Sort
//
//  Created by Andrew Carter on 12/8/16.
//  Copyright © 2016 Andrew Carter. All rights reserved.
//

#include <stdlib.h>
#include <memory.h>

#include "merge.h"


void merge_sort(void *list, intmax_t n, size_t size, comparator compare) {
    if (n > 1) {
        intmax_t mid = n / 2;
        intmax_t left_n = mid;
        intmax_t right_n = n - mid;
        
        merge_sort(list, left_n, size, compare);
        merge_sort(list + (left_n * size), right_n, size, compare);
        
        void *left_list = calloc(left_n, size);
        memcpy(left_list, list, size * left_n);
        
        void *right_list = calloc(right_n, size);
        memcpy(right_list, list + (size * left_n), size * right_n);

        int64_t i = 0;
        int64_t j = 0;
        int64_t k = 0;
        
        while (i < left_n && j < right_n) {
            comparison_result result = compare(left_list + (i * size), right_list + (j * size));
            
            if (result == descending) {
                memcpy(list + (k * size), left_list + (i * size), size);
                i++;
            } else {
                memcpy(list + (k * size), right_list + (j * size), size);
                j++;
            }
            
            k++;
        }
        
        while (i < left_n) {
            memcpy(list + (k * size), left_list + (i * size), size);
            i++;
            k++;
        }
        
        while (j < right_n) {
            memcpy(list + (k * size), right_list + (j * size), size);
            j++;
            k++;
        }
        
        free(left_list);
        free(right_list);
    }
}
