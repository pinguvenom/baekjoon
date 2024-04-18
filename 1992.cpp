#include <bits/stdc++.h>
using namespace std;

int arr[64][64];

void solve(int n, int start_y, int start_x) {
  int val = arr[start_y][start_x];
  for (int i = start_y; i < start_y + n; i++) {
    for (int j = start_x; j < start_x + n; j++) {
      if (arr[i][j] == val) {
        continue;
      } else {
        cout << "(";
        solve(n / 2, start_y, start_x);
        solve(n / 2, start_y, start_x + n / 2);
        solve(n / 2, start_y + n / 2, start_x);
        solve(n / 2, start_y + n / 2, start_x + n / 2);
        cout << ")";
        return;
      }
    }
  }
  cout << val;
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      arr[i][j] = (int)(s[j] - '0');
    }
  }

  solve(n, 0, 0);

  return 0;
}