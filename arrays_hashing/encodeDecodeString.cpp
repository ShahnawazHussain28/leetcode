#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string encode(vector<string> &strs) {
  string msg = "";
  for (int i = 0; i < strs.size(); i++) {
    msg += (to_string(strs[i].length()) + ":" + strs[i]);
  }
  return msg;
}

vector<string> decode(string &str) {
  vector<string> res;
  int i = 0;
  while (i < str.length()) {
    string numStr = "";
    int j = i;
    while (str[j] != ':') {
      numStr += str[j];
      j++;
      i++;
    }
    int num = stoi(numStr);
    string word = "";
    i++;
    while (num > 0) {
      word += str[i];
      num--;
      i++;
    }
    res.push_back(word);
  }
  return res;
}

int main() {
  vector<string> vec{"we", "say", ":", "yes"};
  string enc = encode(vec);
  cout << enc << endl;
  vector<string> dec = decode(enc);
  for (auto i : dec) {
    cout << i << " ";
  }
}
