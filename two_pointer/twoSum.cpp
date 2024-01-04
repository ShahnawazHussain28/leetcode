#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
  int p1 = 0;
  int p2 = numbers.size() - 1;
  while (p1 < p2) {
    int sum = numbers[p1] + numbers[p2];
    if (sum > target)
      p2--;
    else if (sum < target)
      p1++;
    else
      return vector<int>{p1 + 1, p2 + 1};
  }
  return vector<int>{0, 0};
}

int main() {
  vector<int> numbers{-1, 0};
  vector<int> res = twoSum(numbers, -1);
  cout << res[0] << " " << res[1];
  return 0;
}
