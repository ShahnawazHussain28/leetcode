#include <iostream>
#include <vector>

using namespace std;

class MinStack {
public:
  vector<int> stack;
  int minimum = 0;
  MinStack() {
    stack.clear();
    minimum = 0;
  }

  void push(int val) {
    stack.push_back(val);
    minimum = min(minimum, val);
  }

  void pop() { stack.pop_back(); }

  int top() { return stack[stack.size() - 1]; }

  int getMin() { return minimum; }
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
