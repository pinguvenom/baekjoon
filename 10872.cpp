#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  long long rst = 1;
  for (int i = 1; i <= n; i++) {
    rst *= (long long)i;
  }
  cout << rst;
  return 0;
}