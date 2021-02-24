#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node *Node;

void insertFirst(Node head, int data);
void printList(Node);
void insertLast(Node head, int data);
void deleteFirst(Node head);
int length(Node);
void insertAt(Node head, int data);
bool deleteData(Node head, int data);
void deleteLast(Node head);
Node getFirst(Node head);
Node getLast(Node head);
void findIndex(Node head, int data);
bool contains(Node head, int data);
bool isEmpty();

int main(void) {
  Node head = NULL;

  return 0;
}

void insertFirst(Node head, int data) {
  if (head == NULL) {
    Node newHeadNode;
    newHeadNode->data = data;
    newHeadNode->next = NULL;
    return;
  }

  Node newHeadNode;
  newHeadNode->data = data;
  newHeadNode->next = head;
  return;
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
  int counter = 0;

  while (currentNode->next != NULL) {
    counter++;
    currentNode = currentNode->next;
  }

  return counter;
};
