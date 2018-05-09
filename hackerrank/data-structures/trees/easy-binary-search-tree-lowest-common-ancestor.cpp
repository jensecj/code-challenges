/*
  tags: binary search tree, bst, lowest common ancestor, lca, graph theory
  task: find the lowest common ancestor of the bst
*/
#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
  int data;
  Node *left;
  Node *right;
};

bool find(Node* root, vector<Node*>& path, int data) {
  // did not find node with data i
  if(root == NULL) return false;

  path.push_back(root);

  // found it!
  if(root->data == data)
    return true;

  // search in this nodes subtrees, if we find it, return found
  if((root->left && find(root->left, path, data)) ||
     (root->right && find(root->right, path, data))) {
    return true;
  }

  // if not found in left or right subtrees, remove us from path, and
  // return not found
  path.pop_back();
  return false;
}

// we find the paths to both elements we're looking for a lca for, then
// we compare the paths to them to find the lowest node that leads to both
Node* lca(Node* root, int v1, int v2) {
  vector<Node*> p1, p2;

  // if one of the nodes cannot be found in the bst, they have no lca
  if(!find(root, p1, v1) || !find(root, p2, v2))
    return NULL;

  // compare paths until we find the lca
  Node* lca_node = root;
  for (int i = 0; i < p1.size() && i < p2.size(); i++) {
    if(p1[i] != p2[i])
      break;

    lca_node = p1[i];
  }

  return lca_node;
}

int main() {
  Node* a = new Node();
  Node* b = new Node();
  Node* c = new Node();
  Node* d = new Node();
  Node* e = new Node();
  Node* f = new Node();

  a->data = 4;
  b->data = 2;
  c->data = 7;
  d->data = 1;
  e->data = 3;
  f->data = 6;

  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->left = f;
  c->right = NULL;

  Node* n = lca(a, 1, 7);

  cout << n->data << endl;
}
