#include <stdio.h>
#include <time.h>
#include "common.h"

void funcTimer(int* msec, int** result, int* nums, int numsSize, int target, int* returnSize, int*(*func)(int*, int, int, int*)){
    clock_t init_time = clock();
    *result = (*func)(nums, numsSize, target, returnSize);
    clock_t end_time = clock();
    if (msec == NULL)
      msec = 0;
    *msec = *msec + (end_time - init_time) * 1000 / CLOCKS_PER_SEC;
    return;
}

int main(){
  clock_t init_time, end_time;
  int msec = 0;
  int nums[] = {5, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, -3};
  int numsSize = 40;
  int target = 0;
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
    funcTimer(&msec, &result, nums, numsSize, target, &returnSize, twoSum);
    if (i == 0 && result != NULL)
      printf("output: [%d,%d] ", result[0], result[1]);
    //Why not we use free in here. To avoid the lib crt and main crt is different. Where is the var malloced, to free it in there.
    safeFree(&result);
  }
  printf("and test %d spent time: %dms\n", testCounts, msec);
  return 0;
}
