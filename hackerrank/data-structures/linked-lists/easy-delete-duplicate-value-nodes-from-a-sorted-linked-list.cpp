/*
  tags: linked list
  task: given a sorted linked lists, remove duplicated nodes
*/
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node* next;
};

Node* remove_duplicates(Node* head) {
  if(head == NULL)
    return NULL;

  Node* a = head;
  while (a != NULL) {
    if(a->next == NULL)
      break;

    if(a->data == a->next->data)
      while(a->next != NULL && a->data == a->next->data)
        a->next = a->next->next;

    a = a->next;
  }

  return head;
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
  c->data = 1;
  c->next = NULL;
  Node* b = new Node();
  b->data = 1;
  b->next = c;
  Node* a = new Node();
  a->data = 1;
  a->next = b;

  print(a); cout << endl;

  remove_duplicates(a);

  print(a); cout << endl;
}
