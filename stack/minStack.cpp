#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
  stack<int> st;
  stack<int> minimum;
  void push(int val) {
    st.push(val);
    if (minimum.empty())
      minimum.push(val);
    else
      minimum.push(min(minimum.top(), val));
  }
  void pop() {
    st.pop();
    minimum.pop();
  }
  int top() { return st.top(); }
  int getMin() { return minimum.top(); }
};

int main() {
  MinStack *obj = new MinStack();
  obj->push(-2);
  obj->push(0);
  obj->push(-3);
  cout << obj->getMin() << " GetMin\n";
  obj->pop();
  cout << obj->top() << " Top\n";
  cout << obj->getMin() << " GetMin\n";
}
