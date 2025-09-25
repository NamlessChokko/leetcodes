#include "stdbool.h"
#include <stdlib.h>

int findDuplicate(int *nums, int numsSize) {
  bool *hash_table = (bool *)calloc(numsSize, sizeof(bool));

  for (int i = 0; i < numsSize; i++) {
    int current = nums[i];
    if (hash_table[current])
      return current;

    hash_table[current] = 1;
  }

  return 0;
}
