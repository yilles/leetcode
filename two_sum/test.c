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
  int* result;
  init_time = clock();
  for (int i = 0; i < 1000000; ++i)
    result = submit1(nums, numSize, target, &returnSize);
  end_time = clock();
  msec = (end_time - init_time) * 1000 / CLOCKS_PER_SEC;
  if (returnSize != 2)
    return 0;
  printf("submit1 output: [%d,%d] and spent time: %dms\n", result[0], result[1], msec);
  submitFree(result);
  return 0;
}
