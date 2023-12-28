#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> map;
  for (int i = 0; i < nums.size(); i++) {
    int req = target - nums[i];
    if (map.count(req))
      return vector<int>{i, map[req]};
    else
      map[nums[i]] = i;
  }
  return vector<int>{0, 1};
}

int main(int argc, char *argv[]) {
  vector<int> inp{3, 3};
  vector<int> res = twoSum(inp, 6);
  for (int i : res) {
    cout << i << " ";
  }
  return 0;
}
