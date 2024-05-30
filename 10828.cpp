#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  stack<int> stk;

  while (n--) {
    string s;
    cin >> s;

    if (s == "push") {
      int n;
      cin >> n;
      stk.push(n);
    } else if (s == "pop") {
      if (stk.size()) {
        cout << stk.top() << '\n';
        stk.pop();
      } else {
        cout << "-1\n";
      }
    } else if (s == "size") {
      cout << stk.size() << '\n';
    } else if (s == "empty") {
      if (stk.empty()) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    } else if (s == "top") {
      if (stk.size()) {
        cout << stk.top() << '\n';
      } else {
        cout << "-1\n";
      }
    }
  }

  return 0;
}