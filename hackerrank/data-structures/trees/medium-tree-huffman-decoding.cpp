/*
  tags: tree, bst, huffman
  task: decode a string using a huffman tree
*/
#include <iostream>
#include <string>

using namespace std;

struct Node {
  int freq;
  int data;
  Node* left;
  Node* right;
};

void decode_huff(Node* root, string s) {
  Node* node = root;
  for (int i = 0; i < s.length(); i++) {
    if(s[i] == '0')
      node = node->left;
    else if (s[i] == '1')
      node = node->right;

    if(node->data != '\0') {
      cout << node->data;
      node = root;
    }
  }
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

  decode_huff(a, "1001011");
}
