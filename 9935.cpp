#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s, bomb;
  cin >> s;
  cin >> bomb;

  stack<char> stk;
  for (int i = 0; i < s.size(); i++) {
    stk.push(s[i]);

    stack<char> stk2;
    for (int j = bomb.size() - 1; j >= 0; j--) {
      if (stk.size() && stk.top() == bomb[j]) {
        stk2.push(stk.top());
        stk.pop();
      } else {
        break;
      }
    }
    if (stk2.size() == bomb.size()) {
      continue;
    } else {
      while (stk2.size()) {
        stk.push(stk2.top());
        stk2.pop();
      }
    }
  }

  vector<char> vec;
  while (stk.size()) {
    vec.push_back(stk.top());
    stk.pop();
  }
  reverse(vec.begin(), vec.end());
  if (vec.empty()) {
    cout << "FRULA";
  } else {
    for (char c : vec) {
      cout << c;
    }
  }

  return 0;
}