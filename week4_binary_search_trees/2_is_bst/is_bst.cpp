#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>

using std::stack;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool isBSTAux(const vector<Node>& tree, int node, int left_limit, int right_limit){
  if(tree.empty()){
    return true;
  }
  if(node == -1){
    return true;
  }
  int root_value = tree[node].key;
  int left_child = tree[node].left;
  int right_child = tree[node].right;
  if(root_value < left_limit || root_value > right_limit){
    return false;
  }
  if (left_child != -1 && tree[left_child].key >= root_value){
    return false;
  }
  if (right_child != -1 && tree[right_child].key <= root_value){
    return false;
  }
  return isBSTAux(tree,tree[node].left,left_limit,root_value-1) && isBSTAux(tree,tree[node].right,root_value+1,right_limit);
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  return isBSTAux(tree,0,INT_MIN,INT_MAX);
}

int main() {
  
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  int a = 0;
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
