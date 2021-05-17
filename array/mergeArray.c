//
// merge two ordered array
// Created by 毛毛 on 2021/5/17.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct array {
    size_t size;
    size_t len;
    size_t typeSize;
    void* p;
} Array;

Array* createArray() {
    struct Array *array = NULL;
    array = malloc(sizeof(*array ));
    array->size = 0;
    array->len = 0;
    return array;
}

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