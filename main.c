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

int main(void) {
  Node head = NULL;

  printList(head);
  insertFirst(&head, 10);
  printList(head);
  insertFirst(&head, 12);
  insertFirst(&head, 11);
  insertFirst(&head, 15);
  printList(head);

  // insertLast(&head,15)
  // insertAt(&head,10,4)

  return 0;
}

void insertFirst(Node *head, int data) {
  if (*head == NULL) {
    Node newHeadNode;
    newHeadNode = malloc(sizeof(struct Node));

    if (newHeadNode == NULL) {
      exit(EXIT_FAILURE);
    }

    newHeadNode->data = data;
    newHeadNode->next = NULL;
    *head = newHeadNode;
    return;
  }

  Node newHeadNode;
  newHeadNode = malloc(sizeof(struct Node));

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
    Node newHeadNode;
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

  Node newLastNode;
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
    Node newHeadNode;
    newHeadNode = malloc(sizeof(struct Node));

    if (newHeadNode == NULL) {
      exit(EXIT_FAILURE);
    }

    newHeadNode->data = data;
    newHeadNode->next = NULL;
    *head = newHeadNode;
    return;
  }

  Node nodeAtPreviousIndex = getAt(*head, index);

  Node newNodeToInsert;
  newNodeToInsert = malloc(sizeof(struct Node));

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

  while (current != NULL) {
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
      break;
    }

    current = current->next;
  }

  if (current->data == data) {
    return true;
  } else {
    return false;
  }
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