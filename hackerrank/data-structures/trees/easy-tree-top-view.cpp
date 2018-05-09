/*
  tags: tree, bst
  task: print the top view of a bst
*/
#include <iostream>
#include <string>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

// side is an int here because for 0, we want to go both ways (from
// the root)
void top_view(Node* root, int side) {
  if(root == NULL)
    return;

  if(side <= 0)
    top_view(root->left, -1);

  cout << root->data << " ";

  if(side >= 0)
    top_view(root->right, 1);
}

void top_view(Node* root) {
  top_view(root, 0);
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

  top_view(a);
}
