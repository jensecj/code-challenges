/*
  tags: tries, no prefix set
  task: given a set of strings, determine if it is a 'good' or 'bad'
  set. a set is 'good', if no strings are prefixes of any other string
  in the set, otherwise the set is 'bad'.
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

bool insert(TrieNode* trie, string value) {
  bool is_prefixed_by_another_word = false;

  TrieNode* root = trie;
  // iterate through each character of the string to be inserted into
  // the trie
  for(int i = 0; i < value.size(); i++) {
    char c = value[i];
    // if the character already exists in the trie, we need to go
    // deeper to insert, so we update whoose children we're looking
    // at, and go to the next character of the string
    if(root->children.find(c) != root->children.end()) {
      // if this is the case, then we are going to insert a new node
      // after we have already passed a word in the trie, so there
      // exists a prefix for the word we are inserting
      if(root->children[c]->is_terminal)
        is_prefixed_by_another_word = true;

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

  return is_prefixed_by_another_word;
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
  int N; // number of strings in set
  cin >> N;

  TrieNode* trie = new TrieNode();
  trie->parent = NULL;

  bool good_set = true;

  for(int i = 0; i < N; i++) {
    string s;
    cin >> s;

    // if prefixes > 0, it means that the word is already in the trie,
    // before we have inserted it, so, according to the challenge, it
    // prefixes itself. insert returns true if there exists some word
    // in the trie that prefixes the word we're inserting, either way,
    // that makes this a bad set
    if(prefixes(trie, s) > 0 || insert(trie, s)) {
      good_set = false;
      cout << "BAD SET" << endl << s << endl;
      break;
    }

  }
  if(good_set)
    cout << "GOOD SET" << endl;
}
