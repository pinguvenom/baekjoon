#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  int i = 0;
  bool b_fail = false;
  while (true) {
    if (i == s.size()) {
      break;
    }

    if (s[i] == 'p' && s[i + 1] == 'i') {
      i += 2;
    } else if (s[i] == 'k' && s[i + 1] == 'a') {
      i += 2;
    } else if (s[i] == 'c' && s[i + 1] == 'h' && s[i + 2] == 'u') {
      i += 3;
    } else {
      b_fail = true;
      break;
    }
  }
  if (b_fail) {
    cout << "NO";
  } else {
    cout << "YES";
  }

  return 0;
}