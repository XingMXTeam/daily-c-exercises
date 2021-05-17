//
// merge two ordered array
// Created by 毛毛 on 2021/5/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "mergeArray.h"

Array* initArray(Array *array, size_t size, size_t typeSize) {
    if(NULL == array || size == NULL || typeSize == NULL) {
        return;
    }
    void*p = calloc(1, size * typeSize );
    if(p == NULL) {
        return;
    }
    array->p = p;
    array->size = size;
    array->len = 0;
    array->typeSize = typeSize;
    return array;
}

Array* merge(Array *a1, Array*a2, Array *result) {
    void *p1 = a1;
    void *p2 = a2;

    // create merge array
    result = initArray(result, a1->size + s2->size, sizeof(int));

    // compare and copy
    while(&p1 || &p2) {
        if(&p1 < &p2) {
            *result = &p1;
            ++p1;
        }
        else if(&p1 >= &p2) {
            *result = &p2;
            ++p2;
        }
        result++;
    }
    if(!&p1) {
        while(&p2) {
            *result = &p2;
            p2++;
            result++;
        }
    }
    if(!&p2) {
        while(&p1) {
            *result = &p1;
            p1++;
            result++;
        }
    }
    return result;
}

void* printArray(Array *p) {
    for(int i=0; i<p->len; i++) {
        printf("%d\n", &(p+i));
    }
}