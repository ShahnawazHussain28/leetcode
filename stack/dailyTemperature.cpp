#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures) {
  stack<pair<int, int>> st;
  vector<int> res(temperatures.size(), 0);
  st.push(pair<int, int>{0, temperatures[0]});
  for (int i = 1; i < temperatures.size(); i++) {
    int temp = temperatures[i];
    if (temp <= st.top().second) {
      st.push(pair<int, int>{i, temp});
    } else {
      while (!st.empty() && temp > st.top().second) {
        pair<int, int> p = st.top();
        st.pop();
        res[p.first] = i - p.first;
      }
      st.push(pair<int, int>{i, temp});
    }
  }
  return res;
}

int main(int argc, char *argv[]) {
  vector<int> temp{30, 60, 90};
  vector<int> res = dailyTemperatures(temp);
  for (auto i : res)
    cout << i << " ";
  return 0;
}
