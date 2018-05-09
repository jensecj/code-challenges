/*
  tags: bst
  task: traverse the tree in a level ordered fashion
*/
#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

class Node{
public:
  int data;
  Node *left,*right;
  Node(int d){
    data=d;
    left=right=NULL;
  }
};

class Solution{
public:
  Node* insert(Node* root, int data){
    if(root==NULL){
      return new Node(data);
    }
    else{
      Node* cur;
      if(data<=root->data){
        cur=insert(root->left,data);
        root->left=cur;
      }
      else{
        cur=insert(root->right,data);
        root->right=cur;
      }
      return root;
    }
  }

  void levelOrder(Node * root){
    queue<Node*> q;

    if(q.front() == NULL)
      q.push(root);

    while(q.front() != NULL) {
      Node* f = q.front();
      q.pop();

      cout << f->data << " ";

      if(f->left != NULL)
        q.push(f->left);
      if(f->right != NULL)
        q.push(f->right);
    }
  }

};

int main(){
  Solution myTree;
  Node* root = NULL;
  int T, data;

  cin >> T;

  while(T--){
    cin >> data;
    root = myTree.insert(root, data);
  }

  myTree.levelOrder(root);
}
