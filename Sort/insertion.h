//
//  insertion.h
//  Sort
//
//  Created by Andrew Carter on 12/5/16.
//  Copyright © 2016 Andrew Carter. All rights reserved.
//

#pragma once

#include "utility.h"
#include <inttypes.h>

void insertion_sort(void *list, int64_t n, size_t size, CompareFunction compare);
