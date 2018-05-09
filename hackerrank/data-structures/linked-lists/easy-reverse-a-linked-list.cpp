/*
  tags: linked list
  task: given a linked list, reverse it
*/
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node* next;
};

Node* reverse(Node* head) {
  Node* prev = NULL;
  Node* current = head;
  Node* next;
  while(current != NULL) {
    next = current->next; // save the next element we need to look at
    current->next = prev; // flip the direction of the link from this node
    prev = current; // move the 'previous' node along the chain

    current = next; // change the next node we need to look at
  }

  return prev; // prev will be set to the last 'current' node in the chain, e.g. the head
}

void print(Node* head) {
  if(head == NULL)
    return;

  cout << head->data << " -> ";

  if(head->next != NULL)
    print(head->next);
}

int main() {
  Node* b = new Node();
  b->data = 2;
  b->next = NULL;
  Node* a = new Node();
  a->data = 1;
  a->next = b;

  print(a); cout << endl;

  Node* c = reverse(a);

  print(c); cout << endl;
}
