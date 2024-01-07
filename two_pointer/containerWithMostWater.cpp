#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height) {
  int p1 = 0, p2 = height.size() - 1;
  int area = 0;
  while (p1 < p2) {
    int l = height[p1], r = height[p2];
    area = max(area, (p2 - p1) * min(l, r));
    if (l < r)
      p1++;
    else
      p2--;
  }
  return area;
}

int main(int argc, char *argv[]) {
  vector<int> h{1, 1};
  cout << maxArea(h);
  return 0;
}
