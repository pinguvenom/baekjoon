#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int cnt = 1;
  while (true) {
    int val = 3 * cnt * (cnt - 1) + 1;
    if (n <= val) {
      break;
    }
    cnt++;
  }

  cout << cnt;

  return 0;
}