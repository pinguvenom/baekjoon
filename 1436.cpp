#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
  if (s.find("666") != string::npos) {
    return true;
  } else {
    return false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int i = 0;
  int cnt = 0;
  while (true) {
    if (check(to_string(i))) {
      cnt++;
    }
    if (cnt == n) {
      break;
    }
    i++;
  }

  cout << i;

  return 0;
}