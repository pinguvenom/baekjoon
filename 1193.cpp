#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x;
  cin >> x;

  int n = 1;
  while (true) {
    if (x <= n * (n + 1) / 2) {
      break;
    }
    n++;
  }
  int rem = (n + 1) - (n * (n + 1) / 2 - x + 1);
  if (n % 2 == 1) {
    cout << (n + 1) - rem << '/' << rem;
  } else {
    cout << rem << '/' << (n + 1) - rem;
  }

  return 0;
}