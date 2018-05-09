/*
  tags: bst
  task: insert an element into a bst
 */
#include <iostream>
#include <cstddef>
#include <algorithm>

using namespace std;

class Node{
public:
  int data;
  Node *left;
  Node *right;
  Node(int d){
    data = d;
    left = NULL;
    right = NULL;
  }
};

class Solution{
public:
  Node* insert(Node* root, int data) {
    if(root == NULL) {
      return new Node(data);
    }
    else {
      Node* cur;
      if(data <= root->data){
        cur = insert(root->left, data);
        root->left = cur;
      }
      else{
        cur = insert(root->right, data);
        root->right = cur;
      }

      return root;
    }
  }
  int getHeight(Node* root){
    if(root == NULL)
      return -1;

    return max(1 + getHeight(root->left), 1 + getHeight(root->right));
  }
};

int main() {
  Solution myTree;
  Node* root = NULL;
  int t;
  int data;

  cin >> t;

  while(t--){
    cin >> data;
    root = myTree.insert(root, data);
  }

  int height = myTree.getHeight(root);
  cout << height;
}
