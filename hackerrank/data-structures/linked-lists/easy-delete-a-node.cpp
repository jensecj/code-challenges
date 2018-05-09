/*
  tags: linked list
  task: given a linked list, delete a node at some position p
*/
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node* next;
};

Node* Delete(Node* head, int position) {
  if(head == NULL)
    return head;

  if(position == 0)
    return head->next;

  int pos = 0;
  Node* find = head;
  Node* prev = head;
  while(find != NULL && pos < position) {
    prev = find;
    find = find->next;
    pos++;
  }

  prev->next = find->next;
  delete find;
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

  Node* c = Delete(a, 1);

  print(c); cout << endl;
}
