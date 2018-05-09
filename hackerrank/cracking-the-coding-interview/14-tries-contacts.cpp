/*
  tags: tries, word search
  task: make a contact application. it tkes commands 'add' and 'find'.
  'add x' - adds a new name to the contact list
  'find x' - count the number of contacts that are prefixed by x
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

struct TrieNode {
  TrieNode* parent;
  char value;
  bool is_terminal;
  int prefixes;

  // a link to possible children of this node,
  // one for each character in the alphabet, there cannot be two child
  // nodes with the same character, because then it would be further
  // down the tree
  map<char, TrieNode*> children;
};

void insert(TrieNode* trie, string value) {
  TrieNode* root = trie;
  // iterate through each character of the string to be inserted into
  // the trie
  for(int i = 0; i < value.size(); i++) {
    char c = value[i];
    // if the character already exists in the trie, we need to go
    // deeper to insert, so we update whoose children we're looking
    // at, and go to the next character of the string
    if(root->children.find(c) != root->children.end()) {
      root = root->children[c];
      continue;
    } else {
      // if we are here, we need to insert new nodes into the trie
      TrieNode* node = new TrieNode();
      node->value = c;
      node->parent = root;
      root->children[c] = node;

      // indicates that this is a terminal for a word
      if(i == value.size()-1)
        node->is_terminal = true;

      // if this is a terminal node, update all parents to tell them
      // that they prefix yet another word
      if(node->is_terminal) {
        node->prefixes++;
        TrieNode* parent = root;
        while(parent->parent != NULL) {
          parent->prefixes++;
          parent = parent->parent;
        }
      }

      // update children so we can keep inserting nodes
      root = root->children[c];
    }
  }
}

TrieNode* find_node(TrieNode* trie, string query) {
  TrieNode* root = trie;

  bool found = true;

  for(auto& c : query) {
    if(root->children.find(c) != root->children.end()) {
      root = root->children[c];
    } else {
      found = false;
      break;
    }
  }

  if(found) return root;
  else return NULL;
}

int prefixes(TrieNode* trie, string query) {
  TrieNode* node = find_node(trie, query);

  if(node != NULL) return node->prefixes;
  else return 0;
}

int main() {
  int n;
  cin >> n; // number of actions to perform

  TrieNode* trie = new TrieNode();
  trie->parent = NULL;
  for(int i = 0; i < n; i++) {
    string action;
    cin >> action;

    if(action == "add") {
      string input;
      cin >> input;
      insert(trie, input);
    } else if (action == "find") {
      string query;
      cin >> query;
      cout << prefixes(trie, query) << endl;
    } else {
      cout << "error: unknown command: " << action << endl;
    }
  }
}
