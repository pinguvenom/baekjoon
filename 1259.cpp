#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    string s;
    cin >> s;

    if (s == "0") {
      break;
    }

    string s_reverse = s;
    reverse(s_reverse.begin(), s_reverse.end());

    if (s == s_reverse) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }

  return 0;
}