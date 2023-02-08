#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* submit1(int* nums, int numsSize, int target, int* returnSize) {
  int* result = (int*)malloc(sizeof(int)*2);
  for (int i = 0; i < numsSize; ++i) {
    for (int j = i + 1; j < numsSize; ++j) {
      if (target == nums[i] + nums[j]) {
        *returnSize = 2;
        result[0] = i;
        result[1] = j;
        return result;
      }
    }
  }
  return result;
}

void submitFree(int* malloced_int_pointer) {
  if (malloced_int_pointer != NULL) {
    free(malloced_int_pointer);
  }
}