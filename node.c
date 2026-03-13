#include "node.h"
#include <limits.h>
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

Status insertAt(Node **pHead, int index, int value) {
  if (!pHead || index > getLength(*pHead) || index < 0)
    return INVALID_ARGUMENT;

  Node *current = *pHead;
  for (int i = 0; i < index - 1; i++)
    current = current->next;

  Node *new = create(value);
  if (!new)
    return FAILURE;

  if (index == 0) {
    Node *next = *pHead;
    *pHead = new;
    (*pHead)->next = next;
    return SUCCESS;
  }

  Node *next = current->next;
  current->next = new;
  current->next->next = next;

  return SUCCESS;
}

Status removeFirst(Node **pHead) {
  if (!pHead)
    return INVALID_ARGUMENT;

  Node *old = *pHead;
  *pHead = (*pHead)->next;

  free(old);

  return SUCCESS;
}

Status removeLast(Node **pHead) {
  if (!pHead)
    return INVALID_ARGUMENT;

  Node *current = *pHead;

  if (!current->next) {
    free(current);
    *pHead = NULL;
    return SUCCESS;
  }

  while (current->next->next)
    current = current->next;

  free(current->next);
  current->next = NULL;

  return SUCCESS;
}

Status removeAt(Node **pHead, int index) {
  if (!pHead || index > getLength(*pHead) - 1 || index < 0)
    return INVALID_ARGUMENT;

  Node *current = *pHead;

  if (index == 0) {
    *pHead = (*pHead)->next;
    free(current);
    return SUCCESS;
  }

  for (int i = 0; i < index - 1; i++)
    current = current->next;

  Node *old = current->next;
  current->next = current->next->next;

  free(old);

  return SUCCESS;
}

int getFirst(Node *head) {
  if (!head)
    return INVALID_ARGUMENT;

  return head->value;
}

int getLast(Node *head) {
  if (!head)
    return INT_MIN;

  Node *current = head;

  while (current->next)
    current = current->next;

  return current->value;
}

int get(Node *head, int index) {
  if (!head || index > getLength(head) - 1 || index < 0)
    return INT_MIN;

  Node *current = head;

  for (int i = 0; i < index; i++)
    current = current->next;

  return current->value;
}

int findFirst(Node *head, int value) {
  if (!head)
    return -1;

  Node *current = head;
  int index = 0;

  while (current) {
    if (current->value == value)
      return index;

    index++;
    current = current->next;
  }

  return -1;
}
