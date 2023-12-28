#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> freq(string s) {
  vector<int> res(26, 0);
  for (char c : s) {
    res[c - 'a']++;
  }
  return res;
}

bool isAnagram(string s, string t) {
  if (s.length() != t.length())
    return false;
  return freq(s) == freq(t);
}

int main(int argc, char *argv[]) {
  cout << isAnagram("anagram", "nagaram") << endl;
  cout << isAnagram("rat", "car") << endl;
  return 0;
}
