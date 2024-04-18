#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long a, b, v;
  cin >> a >> b >> v;

  cout << (int)ceil((double)(v - b) / (a - b));

  return 0;
}