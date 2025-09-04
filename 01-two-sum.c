/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

#define RETURN_SIZE 2
#define BIG_PRIME 5003

struct HashNode {
  int value;
  int index;
  struct HashNode *next;
};

typedef struct {
  struct HashNode *table[BIG_PRIME];
} HashTable;

HashTable *create_hash(void);
int hash(const int *value);
void insert(HashTable *, const int *value, const int *index);
int get(HashTable *, const int *value);
void free_hash(HashTable *hash_table);

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  int *output = (int *)malloc(RETURN_SIZE * sizeof(int));
  *returnSize = RETURN_SIZE;
  HashTable *hash_table = create_hash();

  for (int i = 0; i < numsSize; i++) {
    int result = 0;
    int get_result = -1;

    if ((get_result = get(hash_table, &nums[i])) != -1) {
      free_hash(hash_table);
      output[0] = i;
      output[1] = get_result;
      return output;
    }

    result = target - nums[i];
    insert(hash_table, &result, &i);
  }

  free_hash(hash_table);
  return NULL;
}

HashTable *create_hash(void) {
  HashTable *new_hash_table = (HashTable *)malloc(sizeof(HashTable));

  for (int i = 0; i < BIG_PRIME; i++) {
    new_hash_table->table[i] = NULL;
  }
  return new_hash_table;
}

int hash(const int *value) {
  int temp = (*value < 0) ? -*value : *value;
  return temp % BIG_PRIME;
}

int get(HashTable *hash_table, const int *value) {
  int h = hash(value);
  struct HashNode *current = hash_table->table[h];

  while (current != NULL) {
    if (current->value == *value) {
      return current->index;
    }
    current = current->next;
  }

  return -1;
}

void insert(HashTable *hash_table, const int *value, const int *index) {
  int h = hash(value);
  struct HashNode *new_node =
      (struct HashNode *)malloc(sizeof(struct HashNode));

  new_node->value = *value;
  new_node->index = *index;
  new_node->next = hash_table->table[h];

  hash_table->table[h] = new_node;
}

void free_hash(HashTable *hash_table) {
  for (int i = 0; i < BIG_PRIME; i++) {
    struct HashNode *current = hash_table->table[i];
    while(current != NULL){
      struct HashNode *temp = current->next;
      free(current);
      current = temp;
    }
    free(current);
  }
  free(hash_table);
}
