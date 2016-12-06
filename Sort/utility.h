//
//  utility.h
//  Sort
//
//  Created by Andrew Carter on 12/5/16.
//  Copyright © 2016 Andrew Carter. All rights reserved.
//

#pragma once

#include <inttypes.h>

typedef enum {
    ascending,
    descending,
    same
} comparison_result;

typedef comparison_result (*CompareFunction)(const void *lhs, const void *rhs);
typedef void (*SortFunction)(void *list, intmax_t n, size_t size, CompareFunction compare);
typedef void (*ListPrintFunction)(const void *list, intmax_t n, size_t size);

comparison_result compare_intmax_t(const void *lhs, const void *rhs);

void pretty_print_intmax_t(const void *list, intmax_t n, size_t size);

void profile_sort(SortFunction sort_function, CompareFunction compare, ListPrintFunction print_function, const void *list, intmax_t n, size_t size);
