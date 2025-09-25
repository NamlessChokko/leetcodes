#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sumZero(int n, int *returnSize) {
  int* result = (int*)calloc(n, n * sizeof(int));
  *returnSize = n;

  for (int i = n / 2; i < n; i++) {
    result[i] = i ;

  }

  return result;
}
