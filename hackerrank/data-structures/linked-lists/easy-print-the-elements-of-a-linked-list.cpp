/*
  tags: linked list
  task: given a linked list, print its elements
*/
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node* next;
};

void print(Node* head) {
  if(head == NULL)
    return;

  cout << head->data << endl;

  if(head->next != NULL)
    print(head->next);
}

int main() {
  Node* a = new Node();
  a->data = 1;
  a->next = NULL;

  print(a);

  Node* b = new Node();
  Node* c = new Node();
  a->next = b;
  b->data = 2;
  b->next = c;
  c->data = 3;
  c->next = NULL;

  print(a);
}
