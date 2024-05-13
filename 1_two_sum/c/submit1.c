#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
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

void safeFree(void** malloced_int_pointer) {
  //malloced_int_pointer != NULL is to avoid: int* result = NULL; safeFree(&result);
  //*malloced_int_pointer != NULL is to avoid free twice and more: safeFree(&result); safeFree(&result);
  //Don't avoid: int* result; safeFree(&result); Please let the pointer initialize to NULL.
  if (malloced_int_pointer != NULL && *malloced_int_pointer != NULL) {
    free(*malloced_int_pointer);
    *malloced_int_pointer = NULL;
  }
}