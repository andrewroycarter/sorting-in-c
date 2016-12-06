//
//  utility.h
//  Sort
//
//  Created by Andrew Carter on 12/5/16.
//  Copyright © 2016 Andrew Carter. All rights reserved.
//

#pragma once

#include <inttypes.h>
#include <stdbool.h>

typedef enum {
    ascending,
    descending,
    same
} comparison_result;

typedef comparison_result (*comparator)(const void *lhs, const void *rhs);
typedef void (*sorter)(void *list, intmax_t n, size_t size, comparator compare);
typedef void (*list_printer)(const void *list, intmax_t n, size_t size);

comparison_result compare_intmax_t(const void *lhs, const void *rhs);

void pretty_print_intmax_t(const void *list, intmax_t n, size_t size);

void profile_sorter(sorter sort, comparator compare, list_printer printer, bool print_list, const void *list, intmax_t n, size_t size);
