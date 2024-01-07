#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
  int fi = 0, se = 0, th = 0;
  for (char c : s) {
    if (c == '(')
      fi++;
    else if (c == '{')
      se++;
    else if (c == '[')
      th++;
    else if (c == ')')
      fi--;
    else if (c == '}')
      se--;
    else if (c == ']')
      th--;
    if (fi < 0 || se < 0 || th < 0) {
      return false;
    }
  }
  return fi == 0 && se == 0 && th == 0;
}

int main(int argc, char *argv[]) {
  cout << isValid("(]");
  return 0;
}
