#include <stdio.h>
#include "array/mergeArray.h"

int main() {
    Array *a1 = [1,2,3];
    Array *a2 = [4,5,6];
    Array *a3 = NULL;

    merge(a1, a2, a3);
    printArray(a3);
    return 0;
}
