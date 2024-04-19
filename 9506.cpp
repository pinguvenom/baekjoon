#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    int n;
    cin >> n;
    if (n == -1) {
      break;
    }

    int sum = 0;
    vector<int> v;
    for (int i = 1; i <= n / 2; i++) {
      if (n % i == 0) {
        sum += i;
        v.push_back(i);
      }
      if (sum > n) {
        break;
      }
    }

    if (sum == n) {
      cout << n << " = ";
      for (int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << " + ";
      }
      cout << v[v.size() - 1] << '\n';
    } else {
      cout << n << " is NOT perfect.\n";
    }
  }

  return 0;
}