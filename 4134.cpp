#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n < 2) {
      n = 2;
    }
    while (true) {
      bool b_prime = true;
      for (long long i = 2; i <= (long long)sqrt(n); i++) {
        if (n % i == 0) {
          b_prime = false;
          break;
        }
      }

      if (b_prime) {
        break;
      }
      n++;
    }
    cout << n << '\n';
  }

  return 0;
}