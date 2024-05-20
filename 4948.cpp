#include <bits/stdc++.h>
using namespace std;

bool era[246913];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 2; i < 246913; i++) {
    if (era[i]) {
      continue;
    }
    for (int j = i * 2; j < 246913; j += i) {
      era[j] = true;
    }
  }

  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }
    int cnt = 0;
    for (int i = n + 1; i <= 2 * n; i++) {
      if (!era[i]) {
        cnt++;
      }
    }
    cout << cnt << '\n';
  }

  return 0;
}