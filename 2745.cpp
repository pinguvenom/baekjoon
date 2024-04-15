#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  int n;

  cin >> s >> n;

  int mul = 1;
  long long rst = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    int val;
    if (s[i] >= 'A' && s[i] <= 'Z') {
      val = (int)(s[i] - 'A' + 10);
    } else {
      val = (int)(s[i] - '0');
    }
    rst += (mul * val);
    mul *= n;
  }

  cout << rst;

  return 0;
}