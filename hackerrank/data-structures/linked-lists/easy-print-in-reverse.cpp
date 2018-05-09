/*
  tags: linked list, print
  task: given a linked list, print its elements in reverse
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

  if(head->next != NULL)
    print(head->next);

  cout << head->data << endl;
}

int main() {
  Node* b = new Node();
  b->data = 2;
  b->next = NULL;
  Node* a = new Node();
  a->data = 1;
  a->next = b;

  print(a); cout << endl;
}
