//
// implement an Array which support delete/add/modify operation
// Created by 毛毛 on 2021/5/14.
//

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdio.h>
#include <stdlib.h>

typeof struct Array {
    size_t size;// the total size
    size_t len;// occupied size
    size_t typeSize;//data type size
    void (*dup)(void *ptr, void *key);
    void (*free)(void *ptr);
    int (*match)(void *ptr, void *key);
    void *p;// save data pointer
} Array;

// macro declare
#define arraySetDupMethod(a, m) ((a)->dup = (m))
#define arraySetFreeMethod(a, m) ((a)->free = (m))
#define arraySetMatchMethod(a, m) ((a)->match = (m))

#define arrayGetDupMethod(a) ((a)->dup)
#define arrayGetFree(a) ((a)->free)
#define arrayGetMatchMethod(a) ((a)->match)

// function declare
Array* arrayCreate();// to declare a function
void arrayInit(Array *array, int size, int typeSize);

int arrayInsert(Array *array, size_t pos, void *const value);//? void *const
size_t arraySearchValue(Array *array, void *const value);
void* arrayIndex(Array *array, size_t index);//?
int arrayModify(Array *array, size_t pos, void *const value);

size_t arrayLen(Array *array);
size_t arraySize(Array *array);

void arrayEmpty(Array *array);
void arrayDelValue(Array *array, void *value);
void arrayDelIndex(Array *array, size_t pos);

#endif // !__ARRAY_H__

