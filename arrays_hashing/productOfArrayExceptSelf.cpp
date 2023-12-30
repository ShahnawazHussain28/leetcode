#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums) {
  int n = nums.size();
  vector<int> res(n, 0);
  long int prod = 1;
  int zeroPos = -1;
  int zeroCount = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] == 0) {
      zeroCount++;
      zeroPos = i;
    } else {
      prod *= nums[i];
    }
  }
  if (zeroCount > 1)
    return res;
  else if (zeroCount == 1) {
    res[zeroPos] = prod;
    return res;
  }
  for (int i = 0; i < n; i++) {
    res[i] = prod / nums[i];
  }
  return res;
}

int main(int argc, char *argv[]) {
  vector<int> inp{1, 2, 3, 4};
  vector<int> res = productExceptSelf(inp);
  for (int i : res) {
    cout << i << " ";
  }
  return 0;
}
