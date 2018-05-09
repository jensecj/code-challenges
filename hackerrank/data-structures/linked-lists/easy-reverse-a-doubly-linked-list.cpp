/*
  tags: linked list
  task: given a doubly linked lists, reverse it
*/
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
  Node* prev;
};

Node* reverse(Node* head) {
  if(head == NULL)
    return NULL;

  Node* current = head;
  while (current != NULL) {
    Node* prev = current->prev;
    current->prev = current->next;
    current->next = prev;

    if(current->prev == NULL)
      break;

    current = current->prev;
  }
  return current;
}

void print(Node* head) {
  if(head == NULL)
    return;

  cout << head->data << " ";

  if(head->next != NULL)
    print(head->next);
}

int main() {
  Node* c = new Node();
  c->data = 3;
  Node* b = new Node();
  b->data = 2;
  Node* a = new Node();
  a->data = 1;

  a->prev = NULL;
  a->next = b;
  b->prev = a;
  b->next = c;
  c->prev = b;
  c->next = NULL;

  print(a); cout << endl;

  Node* r = reverse(a);

  print(r); cout << endl;
}
