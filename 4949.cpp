#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    string s;

    getline(cin, s);
    if (s == ".") {
      break;
    }

    stack<char> stk;
    bool b_fail = false;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(' || s[i] == '[') {
        stk.push(s[i]);
      } else if (s[i] == ')') {
        if (stk.size() && stk.top() == '(') {
          stk.pop();
        } else {
          b_fail = true;
          break;
        }
      } else if (s[i] == ']') {
        if (stk.size() && stk.top() == '[') {
          stk.pop();
        } else {
          b_fail = true;
          break;
        }
      }
    }

    if (b_fail || !stk.empty()) {
      cout << "no\n";
    } else {
      cout << "yes\n";
    }
  }

  return 0;
}