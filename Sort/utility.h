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

// Used to compare two items for sorting.
typedef enum {
    ascending, // If lhs > rhs
    descending, // If lhs < rhs
    same // If lhs == rhs
} comparison_result;

// Function that compares two items and returns the result as a comparison_result.
typedef comparison_result (*comparator)(const void *lhs, const void *rhs);

// Function that sorts a list.
typedef void (*sorter)(void *list, intmax_t n, size_t size, comparator compare);

// Function that prints a list to console.
typedef void (*list_printer)(const void *list, intmax_t n, size_t size);

comparison_result compare_intmax_t(const void *lhs, const void *rhs);

void pretty_print_intmax_t(const void *list, intmax_t n, size_t size);

// Function for profiling the time it takes to sort a list with a given sorter. Outputs results to console.
void profile_sorter(sorter sort, comparator compare, list_printer printer, bool print_list, const void *list, intmax_t n, size_t size);

// Fills dest with random intmax_t's.
void create_list(intmax_t *dest, intmax_t n);
