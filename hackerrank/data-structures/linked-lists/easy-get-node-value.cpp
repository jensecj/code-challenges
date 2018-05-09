/*
  tags: linked list
  task: given a linked lists, find the n'th element from the tail of
  the list
*/
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node* next;
};

// get the n'th node from the tail
int get_node_value(Node* head, int n) {
  if(head == NULL)
    return -1;

  Node* current = head;
  Node* n_behind_current = head;
  int pos = 0;
  while(current != NULL) {
    if(pos > n) {
      n_behind_current = n_behind_current->next;
    }

    pos++;
    current = current->next;
  }

  return n_behind_current->data;
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
  c->next = NULL;
  Node* b = new Node();
  b->data = 2;
  b->next = c;
  Node* a = new Node();
  a->data = 1;
  a->next = b;

  print(a); cout << endl;

  cout << get_node_value(a, 2) << endl;;
}
