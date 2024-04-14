#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  bool arr[110][110] = {false};

  int n;
  cin >> n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    for (int i = x; i < x + 10; i++) {
      for (int j = y; j < y + 10; j++) {
        arr[i][j] = true;
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (arr[i][j]) {
        cnt++;
      }
    }
  }

  cout << cnt;

  return 0;
}