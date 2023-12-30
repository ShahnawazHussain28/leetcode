#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
using namespace std;

bool sortFunc(const vector<int> &v1, const vector<int> &v2) {
  return v1[1] > v2[1];
}

vector<int> topKFrequent(vector<int> &nums, int k) {
  unordered_map<int, int> map;
  for (int num : nums) {
    map[num]++;
  }
  vector<vector<int>> vec;
  for (auto i : map) {
    vec.push_back(vector<int>{i.first, i.second});
  }
  sort(vec.begin(), vec.end(), sortFunc);
  vector<int> res;
  for (int i = 0; i < k; i++) {
    res.push_back(vec[i][0]);
  }
  return res;
}

int main(int argc, char *argv[]) {
  vector<int> vec{1};
  vector<int> res = topKFrequent(vec, 1);
  for (int i : res) {
    cout << i << " ";
  }
  return 0;
}
