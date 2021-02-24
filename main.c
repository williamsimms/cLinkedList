#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node *Node;

void insertFirst(Node *head, int data);
void insertLast(Node *head, int data);
void insertAt(Node *head, int data);
void printList(Node);
void deleteFirst(Node head);
int length(Node);
bool deleteData(Node head, int data);
void deleteLast(Node head);
Node getFirst(Node head);
Node getLast(Node head);
Node getAt(Node head, int index);
void findIndex(Node head, int data);
bool contains(Node head, int data);
bool isEmpty();

int main(void) {
  Node head = NULL;

  // insertFirst(&head,10)
  // insertLast(&head,15)
  // insertAt(&head,10,4)

  return 0;
}

void insertFirst(Node *head, int data) {
  if (*head == NULL) {
    Node newHeadNode;
    newHeadNode = malloc(sizeof(struct Node));
    newHeadNode->data = data;
    newHeadNode->next = NULL;
    *head = newHeadNode;
    return;
  }

  Node newHeadNode;
  newHeadNode = malloc(sizeof(struct Node));
  newHeadNode->data = data;
  newHeadNode->next = *head;
  *head = newHeadNode;
  return;
}

void insertLast(Node *head, int data) {
  Node current = *head;

  if (current == NULL) {
    Node newHeadNode;
    newHeadNode = malloc(sizeof(struct Node));
    newHeadNode->data = data;
    newHeadNode->next = NULL;
    *head = newHeadNode;
    return;
  }

  while (current->next != NULL) {
    current = current->next;
  }

  Node newLastNode;
  newLastNode = malloc(sizeof(struct Node));
  newLastNode->data = data;
  newLastNode->next = NULL;

  current->next = newLastNode;
}

void insertAt(Node *head, int data, int index) {
  Node current = *head;

  if (current == NULL) {
    Node newHeadNode;
    newHeadNode = malloc(sizeof(struct Node));
    newHeadNode->data = data;
    newHeadNode->next = NULL;
    *head = newHeadNode;
    return;
  }

  int counter = 0;

  //
}

Node getFirst(Node head) {
  Node current = head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  return head;
}

Node getLast(Node head) {
  Node current = head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  while (current != NULL) {
    current = current->next;
  }

  return current;
}

Node getAt(Node head, int index) {
  Node current = head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  if (index < 0) {
    puts("Index can not be less than 0");
    exit(EXIT_FAILURE);
  }

  if (index == 0) {
    return head;
  }

  int counter = 0;

  while (current != NULL) {
    if (counter == index) {
      break;
    }

    current = current->next;
    counter++;
  }

  return current;
}

void printList(Node head) {
  Node currentNode = head;

  while (currentNode->next != NULL) {
    printf("%d ->", currentNode->data);
    currentNode = currentNode->next;
  }

  printf("NULL");
}

int length(Node head) {
  Node currentNode = head;

  if (currentNode->next == NULL) {
    return 0;
  }

  int counter = 0;

  while (currentNode->next != NULL) {
    counter++;
    currentNode = currentNode->next;
  }

  return counter;
};
