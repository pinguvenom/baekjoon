#include <bits/stdc++.h>
using namespace std;

deque<int> dq;
bool _map[100001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    _map[i] = x;
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (!_map[i]) {
      dq.push_back(x);
    }
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    dq.push_front(x);

    cout << dq.back() << ' ';
    dq.pop_back();
  }

  return 0;
}