/*
  tags: tree, bst
  task: print a trees nodes during an inorder traversal
*/
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

void in_order_traversal(Node* root) {
  if(root == NULL)
    return;

  in_order_traversal(root->left);
  cout << root->data << " ";
  in_order_traversal(root->right);
}

int main() {
  Node* a = new Node();
  Node* b = new Node();
  Node* c = new Node();
  Node* d = new Node();
  Node* e = new Node();
  Node* f = new Node();

  a->data = 3;
  a->left = b;
  a->right = c;
  b->data = 5;
  b->left = d;
  b->right = e;
  c->data = 2;
  c->left = f;
  c->right = NULL;
  d->data = 1;
  d->left = NULL;
  d->right = NULL;
  e->data = 4;
  e->left = NULL;
  e->right = NULL;
  f->data = 6;
  f->left = NULL;
  f->right = NULL;

  in_order_traversal(a);
}
