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

Status append(Node *head, int value) {
  if (!head)
    return INVALID_ARGUMENT;

  Node *current = head;
  while (current->next)
    current = current->next;

  current->next = create(value);
  if (!current->next)
    return FAILURE;

  return SUCCESS;
}

Status prepend(Node **pHead, int value) {
  if (!pHead)
    return INVALID_ARGUMENT;

  Node *new = create(value);
  if (!new)
    return FAILURE;

  new->next = *pHead;
  *pHead = new;

  return SUCCESS;
}

int getLength(Node *head) {
  if (!head)
    return -1;

  int length = 0;
  Node *current = head;

  while (current) {
    length++;
    current = current->next;
  }

  return length;
}
