#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  stack<pair<long long, int>> stk;

  long long ret = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    int cnt = 1;
    while (stk.size() && stk.top().first <= x) {
      ret += stk.top().second;
      if (stk.top().first == x) {
        cnt = stk.top().second + 1;
      } else {
        cnt = 1;
      }
      stk.pop();
    }
    if (stk.size()) {
      ret++;
    }
    stk.push({x, cnt});
  }

  cout << ret;
  return 0;
}