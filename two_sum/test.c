#include <stdio.h>
#include <time.h>
#include "common.h"

int main(){
  clock_t init_time, end_time;
  int msec;
  int nums[] = {20, 10, 9, 5, 2, 7};
  int numSize = 6;
  int target = 9;
  int returnSize = 0;
  int testCounts = 100000000;
  int* result = NULL;

  init_time = clock();
  printf("target: %d\n", target);
  printf("input: ");
  for (int i = 0; i < numSize; ++i) {
    printf("%d", nums[i]);
    if (i != numSize - 1)
      printf(",");
  }
  printf("\n");
  for (int i = 0; i < testCounts; ++i) {
    result = twoSum(nums, numSize, target, &returnSize);
    if (i == 0)
      printf("output: [%d,%d] ", result[0], result[1]);
    //Why not we use free in here. To avoid the lib crt and main crt is different. Where is the var malloced, to free it in there.
    safeFree(&result);
  }
  end_time = clock();
  msec = (end_time - init_time) * 1000 / CLOCKS_PER_SEC;
  printf("and test %d spent time: %dms\n", testCounts, msec);
  return 0;
}