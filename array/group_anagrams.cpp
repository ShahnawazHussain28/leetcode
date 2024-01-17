#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  unordered_map<string, vector<string>> map;
  for (int i = 0; i < strs.size(); i++) {
    string w = strs[i];
    sort(w.begin(), w.end());
    map[w].push_back(strs[i]);
  }
  vector<vector<string>> res;
  for (auto i : map) {
    res.push_back(i.second);
  }
  return res;
}

int main(int argc, char *argv[]) {
  vector<string> inp{"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> res = groupAnagrams(inp);
  cout << res.size() << "\n";
  for (vector<string> i : res) {
    cout << "\n" << i.size() << ": ";
    for (string j : i) {
      cout << j << " (" << j.length() << ") ";
    }
  }
  return 0;
}
