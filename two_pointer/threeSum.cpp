#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<vector<int>> twoSum(vector<int> &numbers, int target, int start,
                           int end) {
  int p1 = start;
  int p2 = end;
  vector<vector<int>> res;
  while (p1 < p2) {
    int sum = numbers[p1] + numbers[p2];
    if (sum > target)
      p2--;
    else if (sum < target)
      p1++;
    else {
      res.push_back(vector<int>{-target, numbers[p1], numbers[p2]});
      p1++;
      p2--;
      while (numbers[p1] == numbers[p1 - 1] && p1 < p2) {
        p1++;
      }
      while (numbers[p2] == numbers[p2 - 1] && p1 < p2) {
        p2++;
      }
    }
  }
  return res;
}

vector<vector<int>> threeSum(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> res;
  for (int i = 0; i < nums.size(); i++) {
    if (i != 0 && nums[i - 1] == nums[i]) {
      continue;
    }
    int x = nums[i];
    vector<vector<int>> ts = twoSum(nums, -x, i + 1, nums.size() - 1);
    if (ts.size() == 0)
      continue;
    for (vector<int> p : ts) {
      res.push_back(p);
    }
  }
  return res;
}

int main() {
  vector<int> numbers{-2, 0, 3, -1, 4, 0, 3, 4, 1, 1, 1, -3, -5, 4, 0};
  vector<vector<int>> res = threeSum(numbers);
  for (vector<int> v : res) {
    cout << endl;
    for (int i : v) {
      cout << i << " ";
    }
  }
  return 0;
}
