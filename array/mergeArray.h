#ifndef __MERGE_ARRAY_H__
#define __MERGE_ARRAY_H__

typedef struct array {
    size_t size;
    size_t len;
    size_t typeSize;
    void* p;
} Array;

Array* initArray(Array *array, size_t size, size_t typeSize);
Array* merge(Array *a1, Array*a2, Array *result);
void* printArray(Array *p);
#endif