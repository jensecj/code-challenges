/*
  tags: linked list
  task: given a linked list, insert a node at the tail of the list
*/
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node* next;
};

Node* insert(Node* head, int data) {
  Node* node = new Node();
  node->data = data;
  node->next = NULL;

  if(head == NULL)
    return node;

  Node* tail = head;
  while(tail->next != NULL)
    tail = tail->next;

  tail->next = node;

  return head;
}

int main() {
  Node* a = new Node();
  a->data = 1;
  a->next = NULL;

  Node* b = insert(a, 2);
}
