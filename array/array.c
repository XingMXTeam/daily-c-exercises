//
// Created by 毛毛 on 2021/5/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct array {
    int size;
    int used;
    int *arr;
};

void dump(struct array *array) {
    for(int i = 0; i < array->used; i++) {
        printf("[%02d]: %08d\n", i, array->arr[i]);
    }
}
void alloc(struct array *array) {
    array->arr = (int *)
}