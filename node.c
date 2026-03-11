#include "node.h"
#include <stdlib.h>

Node *create(int value) {
  Node *node = malloc(sizeof(*node));
  if (!node)
    return NULL;

  node->value = value;
  node->next = NULL;

  return node;
}

Status destroy(Node *head) {
  if (!head)
    return INVALID_ARGUMENT;

  Node *current = head;

  while (current) {
    Node *next = current->next;
    free(current);
    current = next;
  }

  return SUCCESS;
}
