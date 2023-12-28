#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool containsDuplicate(vector<int> &nums) {
  unordered_map<int, int> map;
  for (int num : nums) {
    if (map.count(num) == 0) {
      map[num] = 1;
    } else {
      return true;
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  vector<int> vec{1, 2, 3, 4, 5, 6, 2};
  cout << containsDuplicate(vec);
  return 0;
}
