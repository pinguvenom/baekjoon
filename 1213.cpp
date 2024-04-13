#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  int alphabet[26] = {0};
  for (auto c : s) {
    alphabet[c - 'A']++;
  }

  string ret = "";
  int odd_cnt = 0;
  int odd_idx = 0;
  for (int i = 25; i >= 0; i--) {
    if (alphabet[i] % 2 == 1) {
      odd_cnt++;
      odd_idx = i;
      alphabet[i]--;
    }
    if (odd_cnt > 1) {
      break;
    }
    for (int j = 0; j < alphabet[i]; j += 2) {
      ret = (char)('A' + i) + ret + (char)('A' + i);
    }
  }

  if (odd_cnt == 1) {
    ret.insert(ret.begin() + ret.size() / 2, (char)('A' + odd_idx));
    cout << ret;
  } else if (odd_cnt == 2) {
    cout << "I'm Sorry Hansoo";
  } else {
    cout << ret;
  }

  return 0;
}