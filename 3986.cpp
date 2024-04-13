#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int cnt = 0;
  while (n--) {
    stack<char> stk;
    string s;
    cin >> s;

    for (auto c : s) {
      if (stk.size() && stk.top() == c) {
        stk.pop();
      } else {
        stk.push(c);
      }
    }

    if (stk.empty()) {
      cnt++;
    }
  }

  std::cout << cnt;
  return 0;
}