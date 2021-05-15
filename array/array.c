//
// dynamic array: from small to big which support space changed by elements add if necessary
//
// Created by 毛毛 on 2021/5/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * size is the array size
 * used is the array size that had already used
 * arr is the pointer to the array that save values
 */
struct array {
    int size;//total size
    int usedSize;// current length
    int *arr;// save data
};

/**
 * to print all the array values
 * @param array  the array struct pointer
 */
void dump(struct array *array) {
    for(int i = 0; i < array->usedSize; i++) {
        printf("[%02d]: %08d\n", i, array->arr[i]);
    }
}

/**
 * to allocate size to the pointer array by the struct array size
 * @param array the array struct pointer
 */
void alloc(struct array *array) {
    array->arr = (int *)malloc(array->size * sizeof(int))
}

/**
 *
 * @param array the struct array pointer
 * @param elem the new inserted element
 * @return
 */
int insert(struct array *array, int elem) {
    int idx;
    if(array->usedSize >= array->size) {
        return -1;
    }
    // find the index
    for(idx = 0; idx < array->usedSize; idx++) {
        if(array->arr[idx] > elem) {
            break;
        }
    }

    // need to move the bigger array
    if(idx < array->usedSize) {
        // array->usedSize - idx right part length
        memmove(&array->arr[idx+1], &array->arr[idx], (array->usedSize - idx) * sizeof (int))
    }
    array->arr[idx] = elem;
    array->used++;
    return idx;
}

int delete(struct  array *array, int idx) {
    if(idx < 0 || idx >= array->usedSize) {
        return -1;
    }
    memmove(&array->arr[idx], &array->arr[idx+1], (array->usedSize - idx - 1)*sizeof (int));
    array->usedSize--;
    return 0;
}

int search(struct array *array, int elem) {
    int idx;
    for(idx = 0; idx < array->usedSize; idx++) {
        if(array->arr[idx] == elem) {
            return idx;
        }
        if(array->arr[idx] > elem) {
            return -1;
        }
    }
    return -1;
}