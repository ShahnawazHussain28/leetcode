#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
  int maxP = 0;
  int l = 0, r = 1;
  while (r < prices.size()) {
    int p = prices[r] - prices[l];
    if (p <= 0) {
      l = r;
      r = l + 1;
    } else {
      if (p > maxP)
        maxP = p;
      r++;
    }
  }
  return maxP;
}
int main(int argc, char *argv[]) {
  vector<int> p{7, 6, 4, 3, 1};
  cout << maxProfit(p);
  return 0;
}
