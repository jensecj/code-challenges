/*
  tags: linked list
  task: given two linked lists, compare them
*/
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node* next;
};

int equal(Node* a, Node* b) {
  // both lists are empty, so they're equal
  if(a == NULL && b == NULL)
    return 1;

  // one of the lists is empty, the other not, they're not equal
  if(a == NULL || b == NULL)
    return 0;

  Node* as = a;
  Node* bs = b;

  while(as != NULL && bs != NULL) {
    // if the nodes have different data, they're not equal
    if(as->data > bs->data || as->data < bs->data)
      return 0;

    // if one of the lists is shorter than the other, they're not equal
    if((as->next != NULL && bs->next == NULL) ||
       (as->next == NULL && bs->next != NULL))
      return 0;

    // move along to the next nodes in the chains
    as = as->next;
    bs = bs->next;
  }

  return 1;
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
  b1->data = 2;
  b1->next = NULL;
  Node* a1 = new Node();
  a1->data = 1;
  a1->next = b1;

  Node* b2 = new Node();
  b2->data = 2;
  b2->next = NULL;
  Node* a2 = new Node();
  a2->data = 1;
  a2->next = b2;


  print(a1); cout << endl;
  print(a2); cout << endl;

  cout << equal(a1, a2) << endl;
}
