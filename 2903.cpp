#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  cout << (int)pow(2 + (int)pow(2, n) - 1, 2);

  return 0;
}