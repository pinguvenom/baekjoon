#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int i = 1;
  while (true) {
    if (i * i > n) {
      break;
    }
    i++;
  }
  cout << i - 1;
  return 0;
}