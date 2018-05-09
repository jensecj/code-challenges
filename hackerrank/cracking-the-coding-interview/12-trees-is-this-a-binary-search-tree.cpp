/*
  tags: tree, bts, binary search tree
  task: given a root node of a tree, determine if it is a binary searc htree
*/
#include <iostream>
#include <climits>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

bool check_bst(Node* root, int min, int max) {
  if(root == NULL)
    return true;

  return
    root->data > min &&
    root->data < max &&
    check_bst(root->left, min, root->data) &&
    check_bst(root->right, root->data, max);
}

bool check_bst(Node* root) {
  return check_bst(root, INT_MIN, INT_MAX);
}

int main() {
  Node* a = new Node();
  Node* b = new Node();
  Node* c = new Node();
  Node* d = new Node();
  Node* e = new Node();
  Node* f = new Node();
  Node* g = new Node();

  a->data = 4;
  b->data = 2;
  c->data = 6;
  d->data = 1;
  e->data = 3;
  f->data = 5;
  g->data = 7;

  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->left = f;
  c->right = g;

  cout << check_bst(a) << endl;
}
