/*
  tags: linked list
  task: given a sorted doubly linked lists, insert a new node (and keep sorted ordering)
*/
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
  Node* prev;
};

Node* insert_rec(Node* head, int data) {
  // inserting into an empty list
  if(head == NULL) {
    Node* node = new Node();
    node->data = data;
    return node;
  }

  if(data < head->data) { // insert some place in the chain
    Node* node = new Node();
    node->data = data;

    node->next = head;
    node->prev = head->prev;

    head->prev = node;
    head = node;
  } else if(head->data <= data) { // keep looking
    head->next = insert_rec(head->next, data);
    head->next->prev = head;
  }

  return head;
}

Node* insert(Node* head, int data) {
  Node* node = new Node();
  node->data = data;
  node->next = NULL;

  if(head == NULL)
    return node;

  Node* current = head;
  Node* prev = head;
  while(current != NULL) {
    if(data <= current->data) {
      cerr << "found node: " << data << " < " << current->data << endl;

      // this is the head node
      if(current->prev == NULL) {
        current->prev = node;
        node->next = current;
        node->prev = NULL;
        return node;
      }

      // the node is somewhere in the chain, we need to change
      // surrounding links
      node->prev = current->prev;
      node->next = current;

      prev->next = node;
      current->prev = node;

      return head;
    }

    // this is the tail node
    if(current->next == NULL) {
      node->next = NULL;
      node->prev = current;
      current->next = node;
      return head;
    }

    prev = current;
    current = current->next;
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
  c->data = 4;
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

  Node* r = insert(a, 1);
  r = insert_rec(r, 2);
  r = insert_rec(r, 3);
  r = insert_rec(r, 4);
  r = insert_rec(r, 5);

  print(r); cout << endl;
}
