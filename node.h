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

/*
 * Creates a node of a linked list
 *
 * @return a pointer to the created node,
 * or NULL if failed.
 * */
Node *create(int value);

/*
 * Frees all nodes of a linked list.
 *
 * @return SUCCESS if the list was destroyed successfully,
 *         INVALID_ARGUMENT if head is NULL
 * */
Status destroy(Node *head);

/*
 * Creates and adds a node to the end of a linked list.
 *
 * @return SUCCESS if the node was appended successfully,
 * FAILURE if failed, or INVALID_ARGUMENT if head is NULL.
 */
Status append(Node *head, int value);

/*
 * Creates and adds a node to the beginning of a linked list.
 *
 * @param pHead A pointer to the head pointer.
 * @param value The value stored in the node.
 * @return SUCCESS if the node was appended successfully,
 * FAILURE if failed, or INVALID_ARGUMENT if pHead is NULL.
 * */
Status prepend(Node **pHead, int value);
Status insertAt(Node *head, int index, int value);

int removeFirst(Node **pHead);
int removeLast(Node *head);
int removeAt(Node *head, int index);

/*
 * Gets the length of a linked list
 *
 * @return length of the linked list,
 * or -1 if head is NULL.
 * */
int getLength(Node *head);
int getFirst(Node *head);
int getLast(Node *head);
int at(Node *head, int index);

int findFirst(Node *head, int value);

#endif
