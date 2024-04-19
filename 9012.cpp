#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    stack<int> stk;
    bool b_fail = false;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        stk.push(s[i]);
      } else {
        if (stk.empty()) {
          b_fail = true;
          break;
        } else {
          stk.pop();
        }
      }
    }

    if (b_fail || stk.size()) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }

  return 0;
}