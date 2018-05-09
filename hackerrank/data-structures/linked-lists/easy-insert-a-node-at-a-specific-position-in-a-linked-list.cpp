/*
  tags: linked list
  task: given a linked list, insert a node at position p
*/
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node* next;
};

Node* insert_nth(Node* head, int data, int position) {
  Node* node = new Node();
  node->data = data;
  node->next = NULL;

  if(head == NULL)
    return node;

  if(position == 0) {
    node->next = head;
    return node;
  }

  int pos = 0;
  Node* tail = head;
  Node* prev = head;
  while(tail->next != NULL && pos < position) {
    prev = tail;
    tail = tail->next;
    pos++;
  }

  prev->next = node;
  node->next = tail;

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
  Node* b = new Node();
  b->data = 2;
  b->next = NULL;
  Node* a = new Node();
  a->data = 1;
  a->next = b;

  print(a); cout << endl;

  Node* c = insert_nth(a, 3, 0);

  print(c); cout << endl;
}
