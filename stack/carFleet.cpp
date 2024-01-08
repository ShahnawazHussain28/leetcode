#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }

int carFleet(int target, vector<int> &position, vector<int> &speed) {
  vector<pair<int, int>> cars;
  for (int i = 0; i < speed.size(); i++) {
    cars.push_back(pair<int, int>{position[i], speed[i]});
  }
  sort(cars.begin(), cars.end(), compare);
  int numFleets = 0;
  stack<pair<int, int>> st;
  for (pair<int, int> c : cars) {
    if (st.empty())
      st.push(c);
    else if (st.top().second > c.second) {
      st.pop();
      numFleets++;
      st.push(c);
    } else if (st.top().second == c.second) {
      if (st.top().first == c.first) {
        continue;
      } else {
        st.pop();
        numFleets++;
        st.push(c);
      }
    } else {
      int relVel = c.second - st.top().second;
      int relDist = st.top().first - c.first;
      int meetTime = relDist / relVel;
      int meetPoint = c.first + (meetTime * c.second);
      if (meetPoint > target) {
        st.pop();
        numFleets++;
        st.push(c);
      } else {
        st.pop();
        st.push(c);
      }
    }
  }
  while (!st.empty()) {
    numFleets++;
    st.pop();
  }
  return numFleets;
}

int main(int argc, char *argv[]) {
  vector<int> pos{0, 2, 4};
  vector<int> speed{4, 2, 1};
  cout << carFleet(100, pos, speed);
  return 0;
}
