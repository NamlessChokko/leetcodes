#include <stdbool.h>

int lengthOfLongestSubstring(char *s) {
  int max_count = 0;
  int j = 0;

  for (int i = 0; s[i]; i++){
    bool table[128] = {0};
    char current = s[i];
    j = i;

    while (s[j] != '\0' && !table[(int)current]) {
      table[(int)current] = true;
      current = s[++j];
    }

    int length = j - i;
    max_count = (length > max_count) ? length : max_count;
  }

  return max_count;
}
