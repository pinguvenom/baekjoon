#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char arr[5][15] = {0};
  for (int i = 0; i < 5; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < s.size(); j++) {
      arr[i][j] = s[j];
    }
  }

  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 5; j++) {
      if (arr[j][i] != 0) {
        cout << arr[j][i];
      }
    }
  }

  return 0;
}