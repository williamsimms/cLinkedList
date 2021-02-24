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
void insertAt(Node *head, int data, int index);
void printList(Node head);
int length(Node head);
Node getFirst(Node head);
Node getLast(Node head);
Node getAt(Node head, int index);
bool isEmpty();
bool contains(Node head, int data);
void removeFirst(Node *head);
void removeLast(Node *head);
void removeAt(Node *head, int index);
int findIndex(Node head, int data);
Node find(Node head, int data);
int count(Node head, int data);
void forEach(Node head, int (*function)(int));
Node findMidpoint(Node head);
Node stepBackFromTail(Node head, int amountToStepBack);
bool isCircular(Node head);
void reverse(Node *head);
void sort(Node head);
bool updateIndex(Node head, int data, int index);
bool updateOne(Node head, int data, int oldData);
int updateMany(Node head, int data, int oldData);
void clear(Node head);
bool updateFirst(Node head, int data);
bool updateLast(Node head, int data);

int main(void) {
  Node head = NULL;

  bool isLinkedListEmpty = isEmpty(head);
  printf("%s \n", isLinkedListEmpty == 1 ? "The Linked List is empty."
                                         : "The Linked List is not Empty.");

  insertFirst(&head, 10);

  printList(head);

  insertFirst(&head, 12);
  insertFirst(&head, 15);

  printList(head);

  insertLast(&head, 8);

  printList(head);

  insertLast(&head, 3);
  insertLast(&head, 1);

  printList(head);

  Node first = getFirst(head);
  printf("First Node -> %d\n", first->data);

  Node last = getLast(head);
  printf("Last Node -> %d\n", last->data);

  Node nodeAtIndexTwo = getAt(head, 2);
  printf("Node at Index of Two -> %d\n", nodeAtIndexTwo->data);

  Node nodeAtIndexFour = getAt(head, 4);
  printf("Node at Index of Four -> %d\n", nodeAtIndexFour->data);

  Node lastNodeFallBack = getAt(head, 100);
  printf(
      "Node at Index of 100, List falls back and returns last element -> %d\n",
      nodeAtIndexFour->data);

  insertAt(&head, 19, 4);
  printList(head);

  insertAt(&head, 2, 0);
  insertAt(&head, 22, 5);
  printList(head);

  removeFirst(&head);
  printList(head);

  removeFirst(&head);
  removeFirst(&head);
  printList(head);

  insertAt(&head, 2, 0);
  insertAt(&head, 22, 5);
  printList(head);

  removeLast(&head);
  printList(head);

  removeLast(&head);
  printList(head);

  removeAt(&head, 2);
  printList(head);

  int indexOf10 = findIndex(head, 10);
  printf("Index of 10 -> %d \n", indexOf10);

  int indexOf22 = findIndex(head, 22);
  printf(
      "Index of 22, falls back and returns index of first instance of 22  -> "
      "%d \n",
      indexOf22);

  Node foundNodeWith19 = find(head, 19);
  printf("Found Node Data -> %d \n", foundNodeWith19->data);

  insertLast(&head, 22);
  printList(head);

  int amountOf22 = count(head, 22);
  printf("The number 22 appears %d Times in the list. \n", amountOf22);

  int lengthOfList = length(head);
  printf("The Linked List is %d nodes long. \n", lengthOfList);

  isLinkedListEmpty = isEmpty(head);
  printf("%s \n", isLinkedListEmpty == 1 ? "The Linked List is empty."
                                         : "The Linked List is not Empty.");

  bool listContains10 = contains(head, 10);
  printf("%s. \n", listContains10 == 1 ? "The Linked List contains 10"
                                       : "The Linked List does not contain 10");

  bool listContains35 = contains(head, 35);
  printf("%s. \n", listContains35 == 1 ? "The Linked List contains 35"
                                       : "The Linked List does not contain 35");

  insertAt(&head, 35, 4);
  printList(head);

  listContains35 = contains(head, 35);
  printf("%s. \n", listContains35 == 1 ? "The Linked List contains 35"
                                       : "The Linked List does not contain 35");

  insertAt(&head, 34, -20);
  printList(head);

  insertAt(&head, 24, 50);
  printList(head);

  return 0;
}

void insertFirst(Node *head, int data) {
  if (*head == NULL) {
    Node newHeadNode = NULL;
    newHeadNode = (Node)malloc(sizeof(struct Node));

    if (newHeadNode == NULL) {
      exit(EXIT_FAILURE);
    }

    newHeadNode->data = data;
    newHeadNode->next = NULL;
    *head = newHeadNode;
    return;
  }

  Node newHeadNode = NULL;
  newHeadNode = (Node)malloc(sizeof(struct Node));

  if (newHeadNode == NULL) {
    exit(EXIT_FAILURE);
  }

  newHeadNode->data = data;
  newHeadNode->next = *head;
  *head = newHeadNode;
  return;
}

void insertLast(Node *head, int data) {
  Node current = *head;

  if (current == NULL) {
    Node newHeadNode = NULL;
    newHeadNode = malloc(sizeof(struct Node));

    if (newHeadNode == NULL) {
      exit(EXIT_FAILURE);
    }

    newHeadNode->data = data;
    newHeadNode->next = NULL;
    *head = newHeadNode;
    return;
  }

  while (current->next != NULL) {
    current = current->next;
  }

  Node newLastNode = NULL;
  newLastNode = malloc(sizeof(struct Node));

  if (newLastNode == NULL) {
    exit(EXIT_FAILURE);
  }

  newLastNode->data = data;
  newLastNode->next = NULL;

  current->next = newLastNode;
}

void insertAt(Node *head, int data, int index) {
  Node current = *head;

  if (current == NULL) {
    Node newHeadNode = NULL;
    newHeadNode = (Node)malloc(sizeof(struct Node));

    if (newHeadNode == NULL) {
      exit(EXIT_FAILURE);
    }

    newHeadNode->data = data;
    newHeadNode->next = NULL;
    *head = newHeadNode;
    return;
  }

  if (index <= 0) {
    insertFirst(head, data);
    return;
  }

  Node nodeAtPreviousIndex = getAt(*head, index - 1);

  if (nodeAtPreviousIndex->next == NULL) {
    insertLast(head, data);
    return;
  }

  Node newNodeToInsert = NULL;
  newNodeToInsert = (Node)malloc(sizeof(struct Node));

  if (newNodeToInsert == NULL) {
    exit(EXIT_FAILURE);
  }

  newNodeToInsert->data = data;
  newNodeToInsert->next = nodeAtPreviousIndex->next;

  nodeAtPreviousIndex->next = newNodeToInsert;

  return;
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
    if (current->next == NULL) {
      return current;
    }

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
    puts("Index can not be less than 0.");
    exit(EXIT_FAILURE);
  }

  if (index == 0) {
    return head;
  }

  int counter = 0;

  while (current->next != NULL) {
    if (counter == index) {
      return current;
    }

    current = current->next;
    counter++;
  }

  return current;
}

void removeFirst(Node *head) {
  Node current = *head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  if (current->next == NULL) {
    *head = NULL;
  }

  Node newHead = current->next;
  *head = newHead;
  free(current);

  return;
}

void removeLast(Node *head) {
  Node current = *head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  if (current->next == NULL) {
    *head = NULL;
  }

  Node next = current->next;

  while (next != NULL) {
    if (next->next == NULL) {
      current->next = NULL;
    }

    current = current->next;
    next = next->next;
  }

  free(next);
}

void removeAt(Node *head, int index) {
  Node current = *head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  Node nodePreviousToIndex = getAt(*head, index - 1);
  Node nodeBeingRemoved = nodePreviousToIndex->next;
  nodePreviousToIndex->next = nodePreviousToIndex->next->next;

  free(nodeBeingRemoved);
}

int findIndex(Node head, int data) {
  Node current = head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  int counter = 0;

  while (current != NULL) {
    if (current->data == data) {
      return counter;
    }

    current = current->next;
    counter++;
  }

  return -1;
}

Node find(Node head, int data) {
  Node current = head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  while (current != NULL) {
    if (current->data == data) {
      return current;
    }

    current = current->next;
  }

  return NULL;
}

int count(Node head, int data) {
  Node current = head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  int counter = 0;

  while (current != NULL) {
    if (current->data == data) {
      counter++;
    }

    current = current->next;
  }

  return counter;
}

int length(Node head) {
  Node current = head;

  if (current == NULL) {
    return 0;
  }

  int counter = 0;

  while (current != NULL) {
    counter++;
    current = current->next;
  }

  return counter;
};

bool isEmpty(Node head) {
  Node currentNode = head;

  if (currentNode == NULL) {
    return true;
  }

  return false;
}

bool contains(Node head, int data) {
  Node current = head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  while (current != NULL) {
    if (current->data == data) {
      return true;
    }

    current = current->next;
  }

  return false;
}

void printList(Node head) {
  Node current = head;

  if (current == NULL) {
    puts("List is Empty.");
    return;
  }

  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }

  printf("NULL\n");
}

Node findMidpoint(Node head) {
  Node current = head;
  Node next = head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  while (next != NULL && next->next->next != NULL) {
    current = current->next;
    next = next->next->next;
  }

  return current;
}

Node stepBackFromTail(Node head, int amountToStepBack) {
  Node current = head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  int counter = 0;

  Node next = current;

  while (counter < amountToStepBack && next != NULL) {
    next = next->next;
    counter++;
  }

  while (next->next != NULL) {
    current = current->next;
    next = next->next;
  }

  return current;
}

bool isCircular(Node head) {
  Node current = head;
  Node next = head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  while (next != NULL && next->next->next != NULL) {
    if (current == next) {
      return true;
    }

    current = current->next;
    next = next->next;
  }

  return false;
}

void forEach(Node head, int (*function)(int)) {
  Node current = head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  while (current != NULL) {
    current->data = function(current->data);
    current = current->next;
  }
}

void reverse(Node *head) {
  Node current = *head;
  Node previous = NULL;
  Node next = NULL;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  while (current != NULL) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  *head = previous;
}

void sort(Node head) {
  Node current = head;
  Node next = NULL;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  while (current != NULL) {
    next = current->next;

    while (next != NULL) {
      if (current->data > next->data) {
        int temp = current->data;
        current->data = next->data;
        next->data = temp;
      }

      next = next->next;
    }

    current = current->next;
  }
}

bool updateIndex(Node head, int data, int index) {
  Node current = head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  int counter = 0;

  while (current != NULL) {
    if (counter == index) {
      current->data = data;
      return true;
    }

    current = current->next;
    counter++;
  }

  return false;
}

bool updateOne(Node head, int data, int oldData) {
  Node current = head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  while (current != NULL) {
    if (current->data == oldData) {
      current->data = data;
      return true;
    }

    current = current->next;
  }

  return false;
}

int updateMany(Node head, int data, int oldData) {
  Node current = head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  int amountUpdated = 0;

  while (current != NULL) {
    if (current->data == oldData) {
      current->data = data;
      amountUpdated++;
    }

    current = current->next;
  }

  return amountUpdated;
}

bool updateFirst(Node head, int data) {
  Node current = head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  head->data = data;
  return true;
}

bool updateLast(Node head, int data) {
  Node current = head;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  Node last = getLast(head);
  last->data = data;
  return true;
}

void clear(Node head) {
  Node current = head;
  Node next = NULL;

  if (current == NULL) {
    puts("List is Empty.");
    exit(EXIT_FAILURE);
  }

  next = head->next;
}
