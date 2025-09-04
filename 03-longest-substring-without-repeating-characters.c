#include <stdbool.h>
#include <stdlib.h>

#define CHARS 256

int lengthOfLongestSubstring(char *s) {
  int max_count = 0;
  int i = 0;
  int j = 0;

  while (s[i] != '\0') {
    bool *table = (bool *)calloc(CHARS, sizeof(bool));
    char current = s[i];
    int index_count = 0;
    j = i;

    while (s[j] != '\0' && !table[(int)current]) {
      table[(int)current] = true;
      current = s[++j];
      index_count++;
    }

    free(table);
    max_count = (index_count > max_count) ? index_count : max_count;
    i++;
  }

  return max_count;
}
