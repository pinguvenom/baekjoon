#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    string s;
    cin >> s;
    int successive_cnt = 0;
    int sum = 0;
    for (char c : s) {
      if (c == 'O') {
        sum += (++successive_cnt);
      } else {
        successive_cnt = 0;
      }
    }
    cout << sum << '\n';
  }

  return 0;
}