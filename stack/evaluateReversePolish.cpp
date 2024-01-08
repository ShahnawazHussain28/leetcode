#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

int evalRPN(vector<string> &tokens) {
  stack<int> st;
  for (string i : tokens) {
    if (i == "+" || i == "-" || i == "*" || i == "/") {
      int num2 = st.top();
      st.pop();
      int num1 = st.top();
      st.pop();
      if (i == "+")
        st.push(num1 + num2);
      else if (i == "-")
        st.push(num1 - num2);
      else if (i == "*")
        st.push(num1 * num2);
      else
        st.push(num1 / num2);
    } else {
      st.push(stoi(i));
    }
  }
  return st.top();
}

int main() {
  vector<string> exp{"10", "6", "9",  "3", "+", "-11", "*",
                     "/",  "*", "17", "+", "5", "+"};
  cout << evalRPN(exp);
  return 0;
}
