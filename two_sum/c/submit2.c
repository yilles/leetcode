#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
  int key;
  int value;
} dictionary;

dictionary* hashTable;

int mod = 701;
//Hash Function
int h(int key) {
  int result = key % mod;
  if (result < 0)
    result = 0 - result;
  return result;
}

dictionary search(int key) {
  int index = h(key);
  return hashTable[index];
}

void insert(int key, int value) {
  int index = h(key);
  hashTable[index].key = key;
  hashTable[index].value = value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  int* result = (int*)malloc(sizeof(int)*2);
  hashTable = (dictionary*)malloc(sizeof(dictionary)*mod);
  for (int i = 0; i < numsSize; ++i) {
    if (search(target - nums[i]).key + nums[i] != target) {
      int key = nums[i];
      int value = i;
      insert(key, value);
    }
    else {
      *returnSize = 2;
      result[0] = search(target - nums[i]).value;
      result[1] = i;
      free(hashTable);
      return result;
    }
  }
  free(hashTable);
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