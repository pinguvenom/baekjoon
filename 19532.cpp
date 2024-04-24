#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  cout << (b * f - c * e) / (b * d - a * e) << ' '
       << (c * d - a * f) / (b * d - a * e);

  return 0;
}