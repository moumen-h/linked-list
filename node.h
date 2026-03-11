#ifndef NODE_H
#define NODE_H

typedef enum Status {
  SUCCESS = 0,
  FAILURE = 1,
  INVALID_ARGUMENT = 2,
} Status;

typedef struct Node {
  struct Node *next;
  int value;
} Node;

Node *create(int value);
Status destroy(Node *head);

Status append(Node *head, int value);
Status prepend(Node **head, int value);
Status insertAt(Node *head, int index, int value);

int removeFirst(Node **head);
int removeLast(Node *head);
int removeAt(Node *head, int index);

int getLength(Node *head);
int getFirst(Node *head);
int getLast(Node *head);
int at(Node *head, int index);

int findFirst(Node *head, int value);

#endif
