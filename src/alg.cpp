// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int longest_len = 0;
  unsigned int max_num = lbound;

  for (uint64_t i = lbound; i <= rbound; i++) {
    unsigned int current_len = collatzLen(i);
    if (current_len > longest_len) {
      longest_len = current_len;
      max_num = i;
    }
  }
  *maxlen = longest_len;
  return max_num;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    len++;
  }
  return len;
}

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    if (num > max) {
      max = num;
    }
  }
  return max;
}
