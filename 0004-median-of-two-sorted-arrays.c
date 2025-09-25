#include <stdio.h>
#include <stdlib.h>

int *merge(int *nums1, int nums1Size, int *nums2, int nums2Size);
int find_median(int *arry, int size);

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {
  int *sorted = merge(nums1, nums1Size, nums2, nums2Size);

  for (int i = 0; i < nums1Size + nums2Size; i++) {
    printf("%d ", sorted[i]);
  }

  printf("\n" );
  return find_median(sorted, nums1Size + nums2Size);
}

int *merge(int *nums1, int nums1Size, int *nums2, int nums2Size) {
  int *new_array = (int *)malloc((nums1Size + nums2Size) * sizeof(int));
  int p1 = 0, p2 = 0, i = 0;

  if (nums1Size == 0) {
    return nums1;
  }
  if (nums2Size == 0) {
    return nums2;
  }

  while (p1 < nums1Size && p2 < nums2Size) {
    if (nums1[p1] <= nums2[p2]) {
      new_array[i] = nums1[p1];
      p1++;
    } else {
      new_array[i] = nums2[p2];
      p2++;
    }
    i++;
  }

  return new_array;
}

int find_median(int *array, int size) {
  if (size % 2) {
    printf("Odd\n");
    printf("Index: %d\n", ((size - 1) / 2) + 1);
    return array[((size - 1) / 2) + 1];
  }

  printf("Even\n");
  printf("Index: %d, %d\n", (int)((size - 1) / 2), ((size - 1) / 2) + 1);
  return (float)(array[(int)((size - 1) / 2)]) +
         (float)(array[(int)((size - 1) / 2) + 1]) / 2;
}
