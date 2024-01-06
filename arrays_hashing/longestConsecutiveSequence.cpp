#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int longestConsecutiveOld(vector<int> &nums) {
  if (nums.size() == 0)
    return 0;
  unordered_set<int> set;
  for (int i = 0; i < nums.size(); i++) {
    set.insert(nums[i]);
  }
  int longest = 0;
  for (int i : set) {
    cout << i << " ";
    if (set.find(i - 1) == set.end()) {
      int curr = i;
      int m = 0;
      while (set.find(curr) != set.end()) {
        m += 1;
        curr++;
      }
      longest = max(longest, m);
    }
  }
  return longest;
}

int longestConsecutive(vector<int> &nums) {
  if (nums.size() == 0)
    return 0;
  unordered_map<int, int> map;
  for (int i = 0; i < nums.size(); i++) {
    map[nums[i]] = i;
  }
  int longest = 0;
  for (auto i : map) {
    if (map.find(i.first - 1) == map.end()) {
      int curr = i.first;
      int m = 0;
      while (map.find(curr) != map.end()) {
        m += 1;
        curr++;
      }
      longest = max(longest, m);
    }
  }
  return longest;
}

int main() {
  vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  cout << longestConsecutive(nums);
  return 0;
}
