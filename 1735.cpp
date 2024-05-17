#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long a, b, c, d;
  cin >> a >> b >> c >> d;

  long long up = a * d + b * c;
  long long down = b * d;

  long long _gcd = gcd(up, down);

  cout << up / _gcd << ' ' << down / _gcd;

  return 0;
}