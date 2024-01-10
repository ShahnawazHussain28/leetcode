#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
  int w = matrix[0].size();
  int p1 = 0;
  int p2 = (w * matrix.size()) - 1;
  while (p1 <= p2) {
    int mid = (p1 + p2) / 2;
    int midVal = matrix[mid / w][mid % w];
    if (midVal < target)
      p1 = mid + 1;
    else if (midVal > target)
      p2 = mid - 1;
    else
      return true;
  }
  return false;
}

int main(int argc, char *argv[]) {
  vector<vector<int>> m{{1}};
  cout << searchMatrix(m, 1);
  return 0;
}
