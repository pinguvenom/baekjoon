#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> vec;
  for (int i = 2; i <= n; i++) {
    if (n % i == 0) {
      vec.push_back(i);
      n /= i;
      i = 1;
    }
  }

  for (int i : vec) {
    cout << i << '\n';
  }

  return 0;
}