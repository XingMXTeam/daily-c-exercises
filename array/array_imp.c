//
// Created by 毛毛 on 2021/5/14.
//

#include "Array.h"
#include <string.h>
#include <stdbool.h>

/**
 * init all value with default value
 * @return array pointer
 */
Array* arrayCreate() {
    struct Array *array = NULL;
    array = malloc(sizeof (*array));// ? create pointer space
    if(NULL == array) {
        return NULL;
    }
    array->p = NULL;
    array->size = 0;
    array->typeSize = 0;//?
    array->len = 0;

    array->dup = NULL;
    array->free = NULL;
    array->match = NULL;

    return array;
}

/**
 * create array by create space
 * @param array  the array pointer
 * @param size array length
 * @param typeSize the array value byte size
 */
void arrayInit(Array *array, int size, int typeSize) {
    if(NULL == array || typeSize <=0 || size < 0) {
        return;
    }

    // create space
    void *p = calloc(1, size * typeSize);
    if(NULL == p) {
        return;
    }

    array->p = p;
    array->len = 0;
    array-size = size;
    array->typeSize = typeSize;
}

/**
 * insert value to the pos position
 * @param array  struct pointer
 * @param pos  insert pos
 * @param value  insert value
 * @return
 */
int arrayInsert(Array *array, size_t pos, void *const value) {
    if(NULL == array) {
        return -1;
    }
    if(array->len >= array->size) {
        return -2;
    }
    if(pos > array->size || pos <= 0) {
        return -3;
    }

    // move pos~last to pos+1~last
    char *pBegin = array->p;//?
    for(size_t i = array->len; i > pos - 1; --i) {
        void *pNew = pBegin + i * array->typeSize;
        void *pOld = pBegin + (i-1)*array->typeSize;
        // copy old to the new position
        if(NULL != array->dup) {
            array->dup(pNew, pOld);
        }
        else {
            // will create space with copy
            memcpy(pNew, pOld, array->typeSize)
        }
    }

    // the target position
    void *pCopy = (void*)(pBegin + ((pos-1)*array->typeSize);
    if(NULL != array->dup) {
        // copy value to the target
        array->dup(pCopy, value)
    }
    else {
        memcpy(pCopy, value, array->typeSize);
    }
    ++array->len;
    return 0;
}

/**
 * search value int the array
 * @param array
 * @param value the target value
 * @return the target index or -1(not find)
 */
size_t arraySearchValue(Array *array, void* const value) {
    // if the array is not exist, return -1
    if(NULL != array) {
        return -1;
    }
    // forEach the array
    char *pBegin = array->p;
    size_t i = 0;
    for(; i < array->len; ++i) {
        int nCmp = 0;
        if(NULL != array->match) {
            nCmp = array->match(pBegin + i * array->typeSize. value);
        }
        else {
            // compare the value with target
            // ?
            nCmp = memcmp(pBegin+i*array->typeSize, value, array->typeSize);
        }
        // find it
        if(nCmp == 0) {
            break;
        }
    }
    // return the target index
    return i;
}

/**
 * return the array index
 * @param array
 * @param index
 * @return the index pointer
 */
void* arrayIndex(Array *array, size_t index) {
    // array is empty
    if(NULL == array) {
        return NULL;
    }
    // out the boundary
    if(index > array->len || index <= 0) {
        return NULL;
    }
    char *pBegin = array->p;
    return pBegin + array->typeSize * (index - 1);
}

/**
 * modify the target value
 * @param array
 * @param pos
 * @param value
 * @return
 */
int arrayModify(Array *array, size_t pos, void *const value) {
    if(NULL != array) {
        return -1;
    }
    if(pos> array->len || pos < 0) {
        return -2;
    }
    char *pBegin = array->p;
    void *pOld = pBegin + (pos-1)*array->typeSize;
    if(NULL != array->dup) {
        array->dup(pOld, value);
    }
    else {
        memcpy(pOld, value, array->typeSize);
    }

    return 0;
}

/**
 * return the array len
 * @param array
 * @return
 */
size_t arrayLen(Array *array) {
    if(NULL == array) {
        return 0;
    }
    return array->len;
}

/**
 * get the opacity of the array
 * @param array
 * @return
 */
size_t arraySize(Array *array) {
    if(NULL == array) {
        rturn 0;
    }
    return array->size;
}

/**
 * free the array
 * @param array
 */
void arrayEmpty(Array *array) {
    if(NULL == array) {
        return;
    }
    free(array->p);
    array->p = NULL;
    free(array);// free the pointer
    array = NULL;
}

/**
 * delete the value
 * @param array
 * @param value
 */
void arrayDelValue(Array *array, void *value) {
    if(NULL != array) {
        return;
    }
    char* pBegin = array0->p;
    bool bCopy = false;// ?
    for(size_t i=0; i< array->len; ++i) {
        if(!bCopy) {
            int nCmp = 0;
            if(NULL != array->match) {
                nCmp = array->match(pBegin + i*array->typeSize, value);
            }
            else {
                nCpm = memcmp(pBegin+i*array->typeSize, value, array->typeSize);
            }
            // find it
            if(0 == nCmp) {
                bCopy = true;
                continue;
            }
        }
        else {
            // copy the next value to the del value
            void *pOld = pBegin + (i + 1) * array->typeSize;
            void *pNew = pBegin + i * array->typeSize;
            if (NULL != array->dup) {
                array->dup(pNew, pOld);
            } else {
                memcpy(pNew, pOld, array->typeSize);
            }
        }
    }

    if(bCopy) {
        --array->len;
    }
}

/**
 * delete the pos value
 * @param array
 * @param pos
 */
void arrayDelIndex(Array *array, size_t pos) {
    if(NULL == array) {
        return;
    }
    if(pos > array->len || pos <=0) {
        return;
    }
    char *pBegin = array->p;
    for(size_t i=pos-1; i<array->len;i++) {
        void *pOld = pBegin + (i+1)*array->typeSize;
        void *pNew = pBegin + i*array->typeSize;
        if(NULL!=array->dup) {
            array->dup(pNew, pOld);
        }
        else {
            memcpy(pNew, pOld, array->typeSize);
        }
    }
    --array->len;
}