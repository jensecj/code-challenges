#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int d){
    data = d;
    next = NULL;
  }
};

class Solution{
public:
  Node* insert(Node *head,int data)
  {
    if(head == NULL)
      return new Node(data);

    Node* c = head;
    while(c->next != NULL) {
      c = c->next;
    }

    Node* node = new Node(data);

    c->next = node;

    return head;
  }

  void display(Node *head)
  {
    Node *start=head;
    while(start)
      {
        cout << start->data << " ";
        start = start->next;
      }
  }
};

int main()
{
  Node* head = NULL;
  Solution mylist;
  int T, data;

  cin >> T;

  while(T-->0){
    cin >> data;
    head = mylist.insert(head, data);
  }

  mylist.display(head);
}
