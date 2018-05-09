/*
  tags: linked list
  task: given two sorted linked lists, merge them
*/
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node* next;
};

// inserts node at the tail of the chain
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

// this approach builds a third list and populates it in an iterative manner
Node* merge(Node* a, Node* b) {
  if(a == NULL && b == NULL)
    return NULL;
  if(a == NULL)
    return b;
  if(b == NULL)
    return a;

  Node* result = NULL;
  Node* as = a;
  Node* bs = b;
  while(as != NULL && bs != NULL) {
    if(as->data < bs->data) {
      result = insert(result, as->data);
      as = as->next;
    } else {
      result = insert(result, bs->data);
      bs = bs->next;
    }

    // if we used all of one list, insert the rest of the other one
    if(as == NULL) {
      while(bs != NULL) {
        result = insert(result, bs->data);
        bs = bs->next;
      }
    }
    if(bs == NULL) {
      while(as != NULL) {
        result = insert(result, as->data);
        as = as->next;
      }
    }
  }

  return result;
}

// a more succinct approach, using recursion
Node* merge_rec(Node* a, Node* b) {
  if(a == NULL) return b;
  if(b == NULL) return a;

  // if this element of a is in the right place, figure out the next
  // element in the list
  if(a->data < b->data) {
    a->next = merge_rec(a->next, b);
    return a;
  } else {
    b->next = merge_rec(a, b->next);
    return b;
  }
}

void print(Node* head) {
  if(head == NULL)
    return;

  cout << head->data << " ";

  if(head->next != NULL)
    print(head->next);
}

int main() {
  Node* b1 = new Node();
  b1->data = 4;
  b1->next = NULL;
  Node* a1 = new Node();
  a1->data = 1;
  a1->next = b1;

  Node* b2 = new Node();
  b2->data = 5;
  b2->next = NULL;
  Node* a2 = new Node();
  a2->data = 2;
  a2->next = b2;

  print(a1); cout << endl;
  print(a2); cout << endl;

  Node* r = merge_rec(a1, a2);

  print(r); cout << endl;
}
