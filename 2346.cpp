#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  deque<pair<int, int>> dq;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    dq.push_back({x, i});
  }

  while (dq.size()) {
    int x, idx;
    tie(x, idx) = dq.front();
    cout << idx << ' ';
    dq.pop_front();

    if (x > 0) {
      for (int i = 0; i < x - 1; i++) {
        dq.push_back(dq.front());
        dq.pop_front();
      }
    } else {
      for (int i = x; i < 0; i++) {
        dq.push_front(dq.back());
        dq.pop_back();
      }
    }
  }

  return 0;
}