#include "node.h"
#include <stdio.h>

/*
 * Returns the n-th number of the fibonacci sequence,
 * or -1 if the parameter is invalid.
 * */
int fibonacci(int n) {
  if (n < 1)
    return -1;

  int x = 0, y = 1, z = x + y;

  for (int i = 1; i < n; i++) {
    x = y;
    y = z;
    z = x + y;
  }

  return x;
}

int main(void) {
  // 1) Store the first 20 fiboncacci numbers in a linked list

  // create the head node
  Node *head = create(fibonacci(1));
  if (!head)
    return 1;

  // append the rest of the fibonacci sequence
  for (int i = 1; i < 20; i++)
    append(head, fibonacci(i + 1));

  // 2) Print the values of the linked list
  for (int i = 0; i < getLength(head); i++) {
    printf("%d\n", get(head, i));
  }

  // 3) Destroy the linked list
  destroy(head);
  head = NULL;

  return 0;
}
