/*
  tags: linked list, cycles
  task: given a linked list, check if it contains a cycle
*/
#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
  int data;
  struct Node* next;
};

bool has_cycle(Node* head) {
  if(head == NULL)
    return false;

  unordered_map<Node*, bool> visited;

  Node* root = head;
  while(root->next != NULL) {
    if(visited[root]) {
      return true;
    } else {
      visited[root] = true;
      root = root->next;
    }
  }

  return false;
}

int main() {
  Node* a = new Node();
  a->data = 1;
  a->next = NULL;

  cout << has_cycle(a) << endl;

  Node* b = new Node();
  Node* c = new Node();
  a->next = b;
  b->data = 2;
  b->next = c;
  c->data = 3;
  c->next = b;

  cout << has_cycle(a) << endl;
}
