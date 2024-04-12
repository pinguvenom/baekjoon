#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  std::cin >> n;

  int cnt = n;
  while (n--) {
    std::string s;
    std::cin >> s;

    char prev_c = ' ';
    bool alphabet[26] = {false};
    for (auto c : s) {
      if (alphabet[c - 'a']) {
        if (c != prev_c) {
          cnt--;
          break;
        }
      }
      alphabet[c - 'a'] = true;
      prev_c = c;
    }
  }

  std::cout << cnt;
  return 0;
}