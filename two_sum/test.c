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
  int* result = NULL;
  init_time = clock();
  for (int i = 0; i < 1000000; ++i) {
    result = submit1(nums, numSize, target, &returnSize);
    if (i == 0)
      printf("submit1 output: [%d,%d] ", result[0], result[1]);
    submitFree(result);
    result = NULL;
  }
  end_time = clock();
  msec = (end_time - init_time) * 1000 / CLOCKS_PER_SEC;
  printf("and spent time: %dms\n", msec);
  return 0;
}