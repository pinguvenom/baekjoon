#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  stack<int> stk;
  int n;
  string s;
  int map[200001];
  cin >> n >> s;
  memset(map, 0, sizeof(map));

  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      stk.push(i);
    } else if (s[i] == ')' && stk.size()) {
      map[stk.top()] = 1;
      map[i] = 1;
      stk.pop();
    }
  }

  int cnt = 0;
  int max_cnt = 0;
  for (int i = 0; i < n; i++) {
    if (map[i] == 1)
      cnt++;
    else {
      max_cnt = max({max_cnt, cnt});
      cnt = 0;
    }
  }

  max_cnt = max({max_cnt, cnt});
  cout << max_cnt;

  return 0;
}