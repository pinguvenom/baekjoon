#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> vec(n, -1);
  stack<pair<int, int>> stk;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    while (stk.size() && a > stk.top().second) {
      vec[stk.top().first] = a;
      stk.pop();
    }
    stk.push({i, a});
  }

  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << ' ';
  }
  return 0;
}