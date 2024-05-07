#include <bits/stdc++.h>
using namespace std;
int n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = s.size() - 1; j >= 0; j--) {
      cout << s[j];
    }
    cout << '\n';
  }

  return 0;
}