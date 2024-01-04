#include <bits/stdc++.h>
#include <cwctype>
#include <iostream>

using namespace std;

bool isPalindrome(string s) {
  int p1 = 0;
  int p2 = s.length() - 1;
  while (p1 <= p2) {
    if (!iswalnum(s[p1])) {
      p1++;
    } else if (!iswalnum(s[p2])) {
      p2--;
    } else {
      if (tolower(s[p1]) != tolower(s[p2])) {
        return false;
      }
      p1++;
      p2--;
    }
  }
  return true;
}

int main() {
  cout << isPalindrome(" ");
  return 0;
}
