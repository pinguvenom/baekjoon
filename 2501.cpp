#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  int cnt = 0;
  bool b_exist = false;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      cnt++;
      if (cnt == k) {
        cout << i;
        b_exist = true;
        break;
      }
    }
  }

  if (!b_exist) {
    cout << "0";
  }

  return 0;
}