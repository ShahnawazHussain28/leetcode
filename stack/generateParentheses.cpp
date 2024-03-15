#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

void generateRecursively(set<string> &sset, string str, int openCount,
                         int closedCount, int n) {
  cout << str << endl;
  if (openCount > n || closedCount > n)
    return;
  if (openCount == n && closedCount == n) {
    sset.insert(str);
    return;
  }
  if (closedCount > openCount) {
    return;
  }
  generateRecursively(sset, str + "(", openCount + 1, closedCount, n);
  generateRecursively(sset, str + ")", openCount, closedCount + 1, n);
}

vector<string> generateParenthesis(int n) {
  set<string> sset;
  string str = "(";
  int openCount = 1, closedCount = 0;
  generateRecursively(sset, str, openCount, closedCount, n);
  return vector<string>(sset.begin(), sset.end());
}

int main(int argc, char *argv[]) {
  vector<string> res = generateParenthesis(8);
  for (string s : res) {
    cout << s << " ";
  }
  return 0;
}
