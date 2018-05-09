/*
  tags: linked list
  task: given two linked lists, that merge at some point, print the
  value of the node where they merge
*/
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

int find_merge_point_iterators(Node* a, Node* b) {
  Node* as = a;
  Node* bs = b;
  while(as != bs) {
    if(as->next == NULL)
      as = b;
    else
      as = as->next;
    if(bs->next == NULL)
      bs = a;
    else
      bs = bs->next;
  }

  return as->data;
}

// since we know that the two lists merge at some point p, we can just
// run through the first list, and set all next pointers to NULL, then
// when we run through the next list, we can just count the number of
// nodes we have to go through to get to the first NULL pointer
int find_merge_point(Node* a, Node* b) {
  Node* as = a;
  while(as != NULL) {
    Node* tmp = as->next;
    as->next = NULL;
    as = tmp;
  }

  Node* bs = b;
  while(bs->next != NULL) {
    bs = bs->next;
  }

  return bs->data;
}

void print(Node* head) {
  if(head == NULL)
    return;

  cerr << head->data << " ";

  if(head->next != NULL)
    print(head->next);
}

int main() {
  Node* d = new Node();
  d->data = 4;
  d->next = NULL;
  Node* c = new Node();
  c->data = 3;
  c->next = d;

  Node* b1 = new Node();
  b1->data = 2;
  Node* a1 = new Node();
  a1->data = 0;

  a1->next = b1;
  b1->next = c;

  Node* a2 = new Node();
  a2->data = 1;

  a2->next = c;

  print(a1); cerr << endl;
  print(a2); cerr << endl;

  cout << "with iterators: " << find_merge_point_iterators(a1, a2) << endl;
  cout << "destructive: " << find_merge_point(a1, a2) << endl;

  print(a1); cerr << endl;
  print(a2); cerr << endl;
}
