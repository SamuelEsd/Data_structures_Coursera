#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::queue;
using std::stack;
using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }


  vector <int> in_order() {
    vector<int> result;
    vector<bool> marked(n,false);
    stack<int> s;
    s.push(0);
    while(!s.empty()){
      int node = s.top();
      if(left[node] == -1 || marked[left[node]]){
        result.push_back(key[node]);
        marked[node] = true;
        s.pop();
        if (right[node] != -1)
        {
          s.push(right[node]);
        }
      }
      else{
        s.push(left[node]);
      }
    }

    return result;
  }

  vector <int> pre_order() {
    vector<int> result;    
    vector<bool> marked(n,false);
    stack<int> s;
    s.push(0);
    while(!s.empty()){
      int node = s.top();
      if(!marked[node]){
        result.push_back(key[node]);
      }
      marked[node] = true;
      if(left[node] == -1 || marked[left[node]]){
        marked[node] = true;
        s.pop();
        if (right[node] != -1)
        {
          s.push(right[node]);
        }
      }
      else{
        s.push(left[node]);
      }
    }
    
    return result;
  }

  vector <int> post_order() {
    vector<int> result;
    vector<bool> marked(n,false);
    stack<int> s;
    s.push(0);
    while(!s.empty()){
      int node = s.top();
      if(left[node] == -1 || marked[left[node]]){
        if (right[node] == -1 || marked[right[node]])
        {
          s.pop();
          result.push_back(key[node]);
          marked[node] = true;
        }
        else{
          s.push(right[node]);
        }
      }
      else{
        s.push(left[node]);
      }
    }
    
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

// 5
// 4 1 2
// 2 3 4
// 5 -1 -1
// 1 -1 -1
// 3 -1 -1

