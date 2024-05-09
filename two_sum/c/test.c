#include <stdio.h>
#include <time.h>
#include "common.h"

void funcTimer(long* time, int** result, int* nums, int numsSize, int target, int* returnSize, int*(*func)(int*, int, int, int*)) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    *result = (*func)(nums, numsSize, target, returnSize);

    clock_gettime(CLOCK_MONOTONIC, &end);
    if (time == NULL)
        *time = 0;
    *time += (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    return;
}

int main() {
    clock_t init_time, end_time;
    long time = 0;
    int nums[] = {2, 7, 11, 15, 27, 30, 49, 81, 121, 143, 171, 197, 203, 239, 279};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 442;
    int returnSize = 0;
    int testCounts = 10000000;
    int* result = NULL;
  
    printf("target: %d\n", target);
    printf("input: ");
    for (int i = 0; i < numsSize; ++i) {
      printf("%d", nums[i]);
      if (i != numsSize - 1)
        printf(",");
    }
    printf("\n");
    for (int i = 0; i < testCounts; ++i) {
      funcTimer(&time, &result, nums, numsSize, target, &returnSize, twoSum);
      if (i == 0 && result != NULL)
        printf("output: [%d,%d] ", result[0], result[1]);
      //Why not we use free in here. To avoid the lib crt and main crt is different. Where is the var malloced, to free it in there.
      safeFree((void**)&result);
    }
    printf("and test %d spent time: %fms\n", testCounts, time / 1e6);
    return 0;
}