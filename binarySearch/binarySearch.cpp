#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target) {
  int p1 = 0;
  int p2 = nums.size() - 1;
  while (p1 <= p2) {
    int mid = (p1 + p2) / 2;
    if (nums[mid] < target)
      p1 = mid + 1;
    else if (nums[mid] > target)
      p2 = mid - 1;
    else
      return mid;
  }
  return -1;
}

int main(int argc, char *argv[]) {
  vector<int> v{-1, 0, 3, 5, 9, 12};
  cout << search(v, 2);
  return 0;
}
