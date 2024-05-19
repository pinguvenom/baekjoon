#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }

  return n * factorial(n - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  cout << factorial(n) / (factorial(k) * factorial(n - k));
  return 0;
}