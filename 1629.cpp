#include <bits/stdc++.h>
using namespace std;

long long calc(long long a, long long b, long long c) {
  if (b == 1) {
    return a % c;
  }

  long long ret = calc(a, b / 2, c);
  ret = (ret * ret) % c;
  if (b % 2 == 1) {
    ret = (ret * a) % c;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long a, b, c;
  cin >> a >> b >> c;

  std::cout << calc(a, b, c);

  return 0;
}